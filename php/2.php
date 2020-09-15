<!DOCTYPE html>
<html>
    <head>
        <title>the answer</title>
    </head>
    <body>
    <?php
        $x = $_POST["first"];
        $y = $_POST["second"];
        $z = $_POST["third"];
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
    </body>
</html>
