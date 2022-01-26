package main

import (
	"fmt"
)

func main() {
	t1 := []int{0, 1, 2, 3, 4, 5, 6, 7}
	fmt.Println(t1[0:3])
	fmt.Println(t1[1:3])
	fmt.Println(t1[0:7])
	fmt.Println(t1[8:])
}
