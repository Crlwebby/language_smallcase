package main

import "fmt"

func main() {
	a := []int{7, 5, 9, 1, 16, 2, 34, 23, 91, 23, 54, 34, 29, 61, 2}
	quicksort(a, 0, len(a)-1)
	fmt.Print(a)
}

func quicksort(a []int, start int, end int) {
	if start >= end {
		return
	}
	j := start - 1
	i := start
	middle := a[end]
	for i = start; i <= end; i++ {
		if a[i] < middle {
			j++
			temp := a[i]
			a[i] = a[j]
			a[j] = temp
		}
	}
	temp := a[end]
	a[end] = a[j+1]
	a[j+1] = temp
	quicksort(a, start, j)
	quicksort(a, j+2, end)
	return
}
