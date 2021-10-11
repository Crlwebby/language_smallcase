package main

import "fmt"

func main() {
	m := 5
	matrix := make([][]int, 3)
	for i := 0; i < len(matrix); i++ {
		matrix[i] = make([]int, m+i)
	}
	fmt.Println(matrix)
	fmt.Println(matrix[0])
}
