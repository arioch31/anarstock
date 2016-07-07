<?php
require_once "Color.class.php";
class Vertex
{
  private $_abscisse;
  private $_ordonnee;
  private $_profondeur;
  private $_coord_h;
  private $_color;
  public static  $verbose = FALSE;

  public static function doc()
  {
    return(file_get_contents("Vertex.doc.txt"));
  }
  public function get_x()
  {
    return($this->_abscisse);
  }
  public function get_y()
  {
    return($this->_ordonnee);
  }
  public function get_z()
  {
    return($this->_profondeur);
  }
  public function get_w()
  {
    return($this->_coord_h);
  }
  public function get_color()
  {
    return($this->_color);
  }

  public function set_x($i)
  {
    $this->_abscisse = $i;
  }
  public function set_y($i)
  {
    $this->_ordonnee = $i;
  }
  public function set_z($i)
  {
    $this->_profondeur = $i;
  }
  public function set_w($i)
  {
    $this->_coord_h = $i;
  }
  public function set_color(Color $c)
  {
    if ($c)
      $this->_color = $c;
    else
      $this->_color = new Color( array( 'red' => 255, 'green' =>   255, 'blue' =>  255 ) );
  }
  public function __construct($tab)
  {
    $this->set_x($tab['x']);
    $this->set_y($tab['y']);
    $this->set_z($tab['z']);

    if (isset($tab['w']))
      $this->set_w($tab['w']);
    else
      $this->set_w(1.0);
    if (isset($tab['color']) && $tab['color'])
      $this->set_color($tab['color']);
    else
    {
      $color = new Color( array( 'red' => 255, 'green' =>   255, 'blue' =>  255 ) );
      $this->set_color($color);
    }
    if(Vertex::$verbose)
      print($this . " constructed.". PHP_EOL);
  }
  public function __destruct()
  {
    if(Vertex::$verbose)
      print($this . " destructed.". PHP_EOL);
  }
  public function __toString()
  {
    if(Vertex::$verbose)
      return (sprintf("Vertex( x: %4.2f, y: %4.2f, z : %4.2f, w: %4.2f, ".$this->_color." )", $this->_abscisse, $this->_ordonnee, $this->_profondeur, $this->_coord_h));
    else
      return (sprintf("Vertex( x: %4.2f, y: %4.2f, z : %4.2f, w: %4.2f )", $this->_abscisse, $this->_ordonnee, $this->_profondeur, $this->_coord_h));
  }

}
?>
