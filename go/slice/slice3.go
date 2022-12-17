//为了测试该死的append值引用传递……坑死我了

package main

import "fmt"

func main() {
	temp := []int{5, 7, 9}
	origin := []int{2, 4, 6}
	var des [][]int
	des = append(des, temp)
	fmt.Println("before append", des)
	des = append(des, origin)
	fmt.Println("after append", des)
	origin[0] = 11
	origin[1] = 13
	origin[2] = 15
	fmt.Println("origin changed ", des)
}
