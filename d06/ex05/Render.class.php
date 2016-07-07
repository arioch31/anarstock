<?php

require_once "Color.class.php";
require_once "Vertex.class.php";
require_once "Matrix.class.php";

class Render
{
  const VERTEX = 0;
  const EDGE = 1;
  const RASTERIZE = 2;
  private $_height;
	private $_width;
	private $_filename;
	private $_image;
  public static  $verbose = FALSE;
  public static function doc()
  {
    return(file_get_contents("Render.doc.txt"));
  }

  public function __construct($tab)
  {
    if(!isset($tab['width']) || !isset($tab['height']) || !isset($tab['filename']))
      return FALSE;
    $this->_height = $tab['height'];
    $this->_width = $tab['width'];
    $this->_filename = $tab['filename'];
    $this->_image = imagecreatetruecolor($this->_width , $this->_height );
    if(Render::$verbose)
      print("Render instance constructed".PHP_EOL);
    return;
  }

  public function __destruct()
  {
    if(Render::$verbose)
    print("Render instance destructed.". PHP_EOL);

  }
  public function renderVertex(Vertex $screenVertex )
  {
    imagesetpixel($this->_image, $screenVertex->get_x(), $screenVertex->get_y(), $screenVertex->get_color()->toPngColor($this->_image));
  }
  public function renderSegment( Vertex $origin, Vertex $end ) {
		$ox =  round($origin->get_x());
		$oy =  round($origin->get_y());
		$ex =  round($end->get_x());
		$ey = round($end->get_y());
		$size = sqrt( pow( $ex - $ox, 2 ) + pow( $ey - $oy, 2 ) );
		$dx = round( $ox - $ex >= 0 ? $ox - $ex : $ex - $ox );
		$dy = round( $oy - $ey >= 0 ? $oy - $ey : $ey - $oy );
		$sx = round( $ox < $ex ? 1 : -1 );
		$sy = round( $oy < $ey ? 1 : -1 );
		$errx = round($dx > $dy ? $dx : -$dy ) / 2;
		while ($ox != $ex || $oy != $ey )
		{
			$current_size = sqrt( pow( $ex - $ox, 2 ) + pow( $ey - $oy, 2 ) );
			$this->renderVertex( new Vertex( ['x' => $ox, 'y' => $oy, 'z' => 1, 'color' => $origin->get_color()->sub($end->get_color())->mult(1 - ($current_size / $size))]));
			$erry = $errx;
			if ( $erry > -$dx )
			{
				$errx -= $dy;
				$ox += $sx;
			}
			if ( $erry < $dy )
			{
				$errx += $dx;
				$oy += $sy;
			}
		}
		$this->renderVertex(new Vertex(['x' => $ox, 'y' => $oy, 'z' => 1, 'color' => $end->get_color()]));
		return;
	}

  public function develop() {
		imagepng($this->_image, $this->_filename);
		return;
	}
}
?>
