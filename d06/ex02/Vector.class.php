<?php
require_once "Color.class.php";
require_once "Vertex.class.php";
class Vector
{
  private $_mag_x;
  private $_mag_y;
  private $_mag_z;
  private $_coord_w;
  public static  $verbose = FALSE;

  public static function doc()
  {
    return(file_get_contents("Vector.doc.txt"));
  }
  public function get_x()
  {
    return($this->_mag_x);
  }
  public function get_y()
  {
    return($this->_mag_y);
  }
  public function get_z()
  {
    return($this->_mag_z);
  }
  public function get_w()
  {
    return($this->_coord_w);
  }


  public function __construct($tab)
  {
    if(!$tab['dest'])
      return FALSE;
    if (!$tab['orig'])
      $origin = new Vertex (array('x' => 0, 'y' => 0, 'z' => 0));
    else
      $origin = $tab['orig'];
    $dest = $tab['dest'];
    $this->_mag_x = $dest->get_x() - $origin->get_x();
    $this->_mag_y = $dest->get_y() - $origin->get_y();
    $this->_mag_z = $dest->get_z() - $origin->get_z();
    $this->_coord_w = 0.0;
    if(Vector::$verbose)
      print($this . " constructed.". PHP_EOL);
  }
  public function __destruct()
  {
    if(Vector::$verbose)
      print($this . " destructed.". PHP_EOL);
  }
  public function __toString()
  {
      return (sprintf("Vector( x: %4.2f, y: %4.2f, z : %4.2f, w: %4.2f )", $this->_mag_x, $this->_mag_y, $this->_mag_z, $this->_coord_w));
  }
  public function magnitude()
  {
    return (sqrt(pow($this->_mag_x, 2) + pow($this->_mag_y, 2) +pow($this->_mag_z, 2)));
  }
  public function normalize()
  {
    $mag = $this->magnitude();
    $vert = new Vertex (array('x'=> $this->get_x() / $mag, 'y'=> $this->get_y() / $mag,'z'=> $this->get_z() / $mag));
    $norm = new Vector (array('dest'=> $vert));
    return ($norm);
  }
  public function add(Vector $plus)
  {
    $vect_sum = new Vertex (array('x'=> $this->get_x() + $plus->get_x(), 'y'=> $this->get_y() + $plus->get_y(), 'z'=> $this->get_z() + $plus->get_z()));
    $ret = new Vector (array('dest' => $vect_sum));
    return ($ret);
  }

  public function sub(Vector $plus)
  {
    $vect_sum = new Vertex (array('x'=> $this->get_x() - $plus->get_x(), 'y'=> $this->get_y() - $plus->get_y(), 'z'=> $this->get_z() - $plus->get_z()));
    $ret = new Vector (array('dest' => $vect_sum));
    return ($ret);
  }
  public function opposite()
  {
    $vert = new Vertex (array('x'=> -$this->get_x(), 'y'=> -$this->get_y(), 'z'=> -$this->get_z()));
    $opp = new Vector (array('dest'=> $vert));
    return ($opp);
  }
  public function scalarProduct($x)
  {
    $vert = new Vertex (array('x'=> $this->get_x() * $x, 'y'=> $this->get_y() * $x,'z'=> $this->get_z() * $x));
    $prod = new Vector (array('dest'=> $vert));
    return ($prod);
  }
  public function dotProduct(Vector $mult)
  {
    $prod = $this->get_x() * $mult->get_x() + $this->get_y() * $mult->get_y() + $this->get_z() * $mult->get_z();
    return ($prod);
  }
  public function cos(Vector $mul)
  {
    $cos = $this->dotProduct($mul) / ($this->magnitude() * $mul->magnitude());
    return ($cos);
  }
  public function crossProduct(Vector $mult)
  {
    $cx = ($this->get_y() * $mult->get_z()) - ($this->get_z() * $mult->get_y());
    $cy = ($this->get_z() * $mult->get_x()) - ($this->get_x() * $mult->get_z());
    $cz = ($this->get_x() * $mult->get_y()) - ($this->get_y() * $mult->get_x());
    $dest = new Vertex (array('x' => $cx,'y'=> $cy,'z' => $cz));
    $prod = new Vector (array('dest' => $dest));
    return ($prod);
  }

}
?>
