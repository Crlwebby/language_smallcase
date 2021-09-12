package main

import "fmt"

func print(ori []int) {
	for i := 0; i < len(ori); i++ {
		fmt.Printf("%d\t", ori[i])
	}
	fmt.Println("")
}

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
	//冒泡排序
	fmt.Println("")

	c := [...]int{1, 3, 5, 7, 9, 11}
	//定义数组
	d := c[:]
	b := make([]int, 10, 20)
	b = append(b, 2, 4)
	print(b)

	print(c[:])
	print(d)
	d[0] = 10
	print(c[:])
	print(d)
	e := []int{1, 2, 3}
	f := make([]int, 10, 20)
	fmt.Println(cap(e))
	fmt.Println(cap(f))
	fmt.Println(c[1:5])
}
