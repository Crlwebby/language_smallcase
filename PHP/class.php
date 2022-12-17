<?php
    namespace APP\Console {
        const app_console = 1;
        class A{
            public function getClassName(){
                return __CLASS__;
            }
            public function getRealName(){
                return static::class;
            }
        }
    }

    namespace {
        class B extends APP\Console\A{
            public function getMyname(){
                return __CLASS__;
            }
        }

        $a = new APP\Console\A;
        $b = new B;

        echo $a->getClassName()."\n";
        echo $a->getRealName()."\n";
        echo $b->getClassName()."\n";
        echo $b->getRealName()."\n";
        echo $b->getMyname()."\n";
    }

?>