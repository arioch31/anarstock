<?php
class Color
{
  public  $red = 0;
  public  $green = 0;
  public  $blue= 0;
  public static  $verbose = FALSE;

  public function __toString()
  {
      return sprintf( "Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green,$this->blue);
  }
  public function __construct($tab)
  {
    if ($tab['rgb'])
    {
      $this->red = intval($tab['rgb'] >> 16);
      $this->green = intval(($tab['rgb'] >> 8) % 256);
      $this->blue = intval($tab['rgb'] % 256);
    }
    else if (isset($tab['red']) && isset($tab['green']) && isset($tab['blue']))
    {
      $this->red = intval($tab['red']);
      $this->green = intval($tab['green']);
      $this->blue = intval($tab['blue']);

    }
    if (Color::$verbose)
      print($this . " constructed.". PHP_EOL);
  }
  public function __destruct()
  {
    if(Color::$verbose)
      print($this . " destructed.". PHP_EOL);
  }
  public static function doc()
  {
    return(file_get_contents("Color.doc.txt"));
  }
  public function add(Color $add)
  {
    if($add)
    {
      $tab['red']= $add->red + $this->red;
      $tab['green']= $add->green + $this->green;
      $tab['blue']= $add->blue +$this->blue;
      $melange = new Color ($tab);
    }
    return($melange);
  }
  public function sub(Color $sub)
  {
    if($sub)
    {
    $tab['red']= $this->red - $sub->red;
    $tab['green']= $this->green - $sub->green;
    $tab['blue'] = $this->blue - $sub->blue;
    $melange = new Color ($tab);
    }
  return($melange);
  }
  public function mult($multi)
  {
    $tab['red'] =   $this->red * $multi;
    $tab['green'] =  $this->green * $multi;
    $tab['blue'] =  $this->blue * $multi;
    $melange = new Color ($tab);
    return($melange);
  }
}
?>
