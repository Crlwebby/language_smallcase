<?php
    $x = $_GET["first"];
    $y = $_GET["second"];
    $z = $_GET["third"];
    $temp = $x;
    if($x>$y){
        $x=$y;
        $y=$temp;
    }
    if($x>$z){
        $temp = $z;
        $z = $x;
        $x = $temp;
    }
    if($y>$z){
        $temp =$y;
        $y = $z;
        $z = $temp;
    }
    echo $x."   ".$y."  ".$z."   "."\n";
?>