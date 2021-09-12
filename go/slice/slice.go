package main

import "fmt"

func main() {
	vals := make([]int, 5)
	//make定义切片，预定义容量，默认都初始化为零
	fmt.Println("Capacity was: ", cap(vals))
	for i := 0; i < 5; i++ {
		vals = append(vals, i)
	}
	//添加五个元素后，切片容量为10
	fmt.Println("now capacity is: ", cap(vals))
	fmt.Println(vals)

	var temp []int
	for i := 0; i < 5; i++ {
		temp = append(temp, i)
	}
	fmt.Println(temp)
}
