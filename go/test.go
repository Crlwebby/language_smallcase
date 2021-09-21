package main

import "fmt"

func main() {
	a := [5]int{1, 2, 3, 4, 5}
	b := a
	b[0] = 10
	fmt.Println(b)
	fmt.Println(a)
}
