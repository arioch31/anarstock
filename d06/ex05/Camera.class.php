<?php
require_once "Color.class.php";
require_once "Vertex.class.php";
require_once "Matrix.class.php";
class Camera
{
  public static  $verbose = FALSE;
  private  $_origin;
  private  $_tT;
  private  $_tR;
  private  $_wiew;
  private  $_proj;

  public static function doc()
  {
    return(file_get_contents("Camera.doc.txt"));
  }
  public function __toString()
  {
    $ret = "Camera( ". PHP_EOL;
    $ret .= "+ Origine: ".$this->_origin. PHP_EOL;
    $ret .= "+ tT:".PHP_EOL.$this->_tT;
    $ret .= "+ tR:".PHP_EOL.$this->_tR;
    $ret .= "+ tR->mult( tT ):".PHP_EOL.$this->_wiew;
    $ret .= "+ Proj:".PHP_EOL.$this->_proj;
    return ($ret);
  }
  private function err_check($tab)
  {
    if (!isset($tab['origin']) || !isset($tab['orientation']))
        return TRUE;
    if((isset($tab['width']) || isset($tab['height'])) && isset($tab['ratio']))
        return TRUE;
    if(!(isset($tab['width']) && isset($tab['height'])) && !isset($tab['ratio']))
        return TRUE;
    if (!isset($tab['fov']) ||!isset($tab['near']) ||!isset($tab['far']))
      return TRUE;
    return (FALSE);
  }
  public function __construct($tab)
  {
    if ($this->err_check($tab))
    return FALSE;

    $dest = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0));
    $this->_origin  = $tab['origin'];

    $vect = new Vector (array('orig' =>$this->_origin , 'dest'=> $dest));
    $this->_tT = new Matrix(array('preset'=> Matrix::TRANSLATION, 'vtc' => $vect));
    if (isset($tab['ratio']))
      $this->_proj = new Matrix(array('preset'=> Matrix::PROJECTION,'fov'=> $tab['fov'],'ratio'=> $tab['ratio'],'near'=> $tab['near'],'far'=> $tab['far']));
    else
    $this->_proj = new Matrix(array('preset'=> Matrix::PROJECTION,'fov'=> $tab['fov'],'ratio'=> $tab['width'] / $tab['height'],'near'=> $tab['near'],'far'=> $tab['far']));
    $this->_tR = $tab['orientation'];
    $this->_wiew = $this->_tR->mult($this->_tT);
    if(Camera::$verbose)
      print("Camera instance constructed.". PHP_EOL);
  }
  public function __destruct()
  {
    if(Camera::$verbose)
    print("Camera instance destructed.". PHP_EOL);

  }
  public function watchVertex(Vertex $w)
  {
    $res = $this->_wiew->transformVertex($w);
    $res = $this->_proj->transformVertex($res);
    return $res;
  }

}
?>
