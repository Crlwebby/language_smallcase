package main

import "fmt"

func main() {
	vals := make([]int, 5)
	fmt.Println("Capacity was: ", cap(vals))
	for i := 0; i < 5; i++ {
		vals = append(vals, i)
	}
	fmt.Println("now capacity is: ", cap(vals))
	fmt.Println(vals)

	var temp []int
	for i := 0; i < 5; i++ {
		temp = append(temp, i)
	}
	fmt.Println(temp)
}
