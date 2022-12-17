package main

import "fmt"

func changeSlice(s []int) {
	fmt.Printf("func: %p \n", &s)
	s[1] = 111
}

func main() {
	slice := []int{0, 1, 2, 3}
	fmt.Printf("slice: %v slice addr %p \n", slice, &slice)

	changeSlice(slice)
	fmt.Printf("slice: %v slice addr %p \n", slice, &slice)
}
