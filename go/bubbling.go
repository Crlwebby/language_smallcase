package main

import "fmt"

func main() {
	a := []int{7, 5, 9, 1, 16, 2, 34, 23, 91, 23, 54, 34, 29, 61, 2}
	for i := 0; i < len(a); i++ {
		for j := len(a) - 1; j > i; j-- {
			if a[j] < a[i] {
				temp := a[j]
				a[j] = a[i]
				a[i] = temp
			}
		}
	}
	for _, i := range a {
		fmt.Printf("%d\t", i)
	}
}
