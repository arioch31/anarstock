<?php

require_once "Color.class.php";
require_once "Vertex.class.php";
require_once "Matrix.class.php";

class Triangle
{

  private $ab;
  private $ac;
  private $bc;
  public static  $verbose = FALSE;
  public static function doc()
  {
    return(file_get_contents("Triangle.doc.txt"));
  }

  public function __construct($tab)
  {
    if(!isset($tab['A']) || !isset($tab['B']) || !isset($tab['C']))
      return FALSE;
      $a = $tab['A'];
      $b = $tab['B'];
      $c = $tab['C'];
      $this->ab = new Vector (array('orig' => $a, 'dest'=> $b));
      $this->ac = new Vector (array('orig' => $a, 'dest'=> $c));
      $this->bc = new Vector (array('orig' => $b, 'dest'=> $c));

    if(Triangle::$verbose)
        print("Triangle instance constructed".PHP_EOL);
    return($this);
  }

  public function __destruct()
  {
    if(Triangle::$verbose)
    print("Triangle instance destructed.". PHP_EOL);

  }
}
?>
