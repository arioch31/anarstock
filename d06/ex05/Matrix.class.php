<?php
require_once "Color.class.php";
require_once "Vertex.class.php";
class Matrix
{
  const IDENTITY = "IDENTITY";
  const SCALE = "SCALE";
  const RX = "RX";
  const RY = "RY";
  const RZ = "RZ";
  const TRANSLATION = "TRANSLATION";
  const PROJECTION = "PROJECTION";
  const CONSTRUCT = "CONSTRUCT";
  private $_type;
  private $_presets = array(IDENTITY, SCALE, RX, RY, RZ, TRANSLATION, PROJECTION, CONSTRUCT);
  private $_pre_rot = array(RX, RY, RZ);
  private $_matrix = array();
  public static  $verbose = FALSE;

  public static function doc()
  {
    return(file_get_contents("Matrix.doc.txt"));
  }
  public function __toString()
  {
    $ret = "M | vtcX | vtcY | vtcZ | vtxO". PHP_EOL. "-----------------------------" .PHP_EOL;
    $ret .= sprintf("x | %4.2f | %4.2f | %4.2f | %4.2f",$this->_matrix['x']['x'],$this->_matrix['x']['y'],$this->_matrix['x']['z'],$this->_matrix['x']['w']) .PHP_EOL;
    $ret .= sprintf("y | %4.2f | %4.2f | %4.2f | %4.2f",$this->_matrix['y']['x'],$this->_matrix['y']['y'],$this->_matrix['y']['z'],$this->_matrix['y']['w']) .PHP_EOL;
    $ret .= sprintf("z | %4.2f | %4.2f | %4.2f | %4.2f",$this->_matrix['z']['x'],$this->_matrix['z']['y'],$this->_matrix['z']['z'],$this->_matrix['z']['w']) .PHP_EOL;
    $ret .= sprintf("w | %4.2f | %4.2f | %4.2f | %4.2f",$this->_matrix['w']['x'],$this->_matrix['w']['y'],$this->_matrix['w']['z'],$this->_matrix['w']['w']) .PHP_EOL;
    return ($ret);
  }
  private static function _ident()
  {
    $matrix['x'] = array('x'=>1, 'y'=> 0, 'z'=> 0, 'w'=> 0);
    $matrix['y'] = array('x'=>0, 'y'=> 1, 'z'=> 0, 'w'=> 0);
    $matrix['z'] = array('x'=>0, 'y'=> 0, 'z'=> 1, 'w'=> 0);
    $matrix['w'] = array('x'=>0, 'y'=> 0, 'z'=> 0, 'w'=> 1);
    return($matrix);
  }
  private function _translate(Vector $v)
  {
    $this->_matrix['x']['w'] += $v->get_x();
    $this->_matrix['y']['w'] += $v->get_y();
    $this->_matrix['z']['w'] += $v->get_z();
  }

  private function _scale($scale)
  {
    foreach ($this->_matrix as $key => $row)
      foreach ($row as $key2 => $value)
        if ($key != 'w' && $key2 != 'w')
          $this->_matrix[$key][$key2] = $value * $scale;
    $this->_type = "SCALE";
  }
  private function _rot($angle, $axis)
  {
    if ($axis == 'x')
    {
      $this->_matrix['y']['y'] = cos($angle);
      $this->_matrix['z']['z'] = cos($angle);
      $this->_matrix['y']['z'] = -sin($angle);
      $this->_matrix['z']['y'] = sin($angle);
      $this->_type = "Ox ROTATION";
    }
    if ($axis == 'y')
    {
      $this->_matrix['x']['x'] = cos($angle);
      $this->_matrix['z']['z'] = cos($angle);
      $this->_matrix['x']['z'] = sin($angle);
      $this->_matrix['z']['x'] = -sin($angle);
      $this->_type = "Oy ROTATION";
    }
    if ($axis == 'z')
    {
      $this->_matrix['y']['y'] = cos($angle);
      $this->_matrix['x']['x'] = cos($angle);
      $this->_matrix['y']['x'] = sin($angle);
      $this->_matrix['x']['y'] = -sin($angle);
      $this->_type = "Oz ROTATION";
    }
  }


  private function _projection($angle, $ratio, $near, $far)
  {
    $this->_matrix['x']['x'] = 1 / ($ratio * tan(($angle * M_PI /180) / 2));
    $this->_matrix['y']['y'] = 1 / tan(($angle * M_PI /180) / 2);
    $this->_matrix['z']['z'] = ($near + $far) / ($near -$far);
    $this->_matrix['z']['w'] = 2 * $far * $near /($near - $far);
    $this->_matrix['w']['z'] = -1;
    $this->_type = "PROJECTION";

  }

  private function err_check($tab)
  {
    if (!$tab['preset'] || !in_array($tab['preset'], $this->_presets))
     return(TRUE);
      $this->_type = $tab['preset'];
    if ($tab['preset'] === SCALE && !isset($tab['scale']))
      return(TRUE);
    if (in_array($tab['preset'], $this->_pre_rot) && !isset($tab['angle']))
      return(TRUE);

    if ($tab['preset'] === TRANSLATION && !isset($tab['vtc']))
        return(TRUE);

    if ($tab['preset'] === PROJECTION &&
        (!isset($tab['fov']) || !isset($tab['ratio'])
        ||!isset($tab['near']) ||!isset($tab['far'])))
        return(TRUE);
    return(FALSE);
  }
  public function __construct($tab)
  {
    if ($this->err_check($tab))
      return (FALSE);
    $this->_matrix = $this->_ident();
    if ($tab['preset'] == IDENTITY)
      $this->_type = "IDENTITY";
    if ($tab['preset'] == SCALE)
      $this->_scale($tab['scale']);
    if ($tab['preset'] == RX)
      $this->_rot($tab['angle'], 'x');
    if ($tab['preset'] == RY)
      $this->_rot($tab['angle'], 'y');
    if ($tab['preset'] == RZ)
        $this->_rot($tab['angle'], 'z');
    if ($tab['preset'] == TRANSLATION)
        $this->_translate($tab['vtc']);
    if ($tab['preset'] == PROJECTION)
        $this->_projection($tab['fov'], $tab['ratio'], $tab['near'], $tab['far']);
    if(Matrix::$verbose && $tab['preset'] != CONSTRUCT)
      print("Matrix ".$this->_type." preset instance constructed".PHP_EOL);
    return($this);

  }
  public function __destruct()
  {
    if(Matrix::$verbose)
    print("Matrix instance destructed.". PHP_EOL);

  }
  public function transformVertex(Vertex $v)
  {
    $x = $this->_matrix['x']['x'] * $v->get_x() +$this->_matrix['x']['y'] * $v->get_y();
    $x += $this->_matrix['x']['z'] * $v->get_z() +$this->_matrix['x']['w'] * $v->get_w();
    $y = $this->_matrix['y']['x'] * $v->get_x() +$this->_matrix['y']['y'] * $v->get_y();
    $y += $this->_matrix['y']['z'] * $v->get_z() +$this->_matrix['y']['w'] * $v->get_w();
    $z = $this->_matrix['z']['x'] * $v->get_x() +$this->_matrix['z']['y'] * $v->get_y();
    $z += $this->_matrix['z']['z'] * $v->get_z() +$this->_matrix['z']['w'] * $v->get_w();
    $w = $this->_matrix['w']['x'] * $v->get_x() +$this->_matrix['w']['y'] * $v->get_y();
    $w += $this->_matrix['w']['z'] * $v->get_z() +$this->_matrix['w']['w'] * $v->get_w();
    $res = new Vertex(array('x' =>$x, 'y' => $y, 'z'=>$z, 'w'=>$w));
    return($res);
  }

  public function mult(Matrix $poulpe)
  {
    $res = new Matrix (array('preset' => CONSTRUCT));
    foreach ($this->_matrix as $k1 => $v1)
      foreach ($poulpe->_matrix as $k2 => $v2)
      {
        $res->_matrix[$k1][$k2] = 0.0;
        foreach($poulpe->_matrix as $k3 => $v3)
          $res->_matrix[$k1][$k2] += $this->_matrix[$k1][$k3] * $poulpe->_matrix[$k3][$k2];
      }
    return($res);
  }
}
?>
