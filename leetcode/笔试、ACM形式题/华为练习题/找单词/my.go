package main

import "fmt"

func in(x int, y int, s []int) bool {
	//s相当于visited数组，存的是(x,y)的下标，因而每次步长+2;
	for i := 0; i < len(s); i = i + 2 {
		if s[i] == x && s[i+1] == y {
			return true
		}
	}
	return false
}

func find_word(array [][]byte, s string) bool {
	n := len(s)
	row := len(array)
	column := len(array[0])
	result := make([]int, 2*n)
	//result存遍历过的点，以(x,y)的形式存取
	op := [][]int{{0, -1}, {-1, 0}, {1, 0}, {0, 1}}
	var check func(i, j, k int) bool
	check = func(i, j, k int) bool {
		if array[i][j] != s[k] {
			return false
		}
		result[2*k], result[2*k+1] = i, j
		if k == n-1 {
			return true
		}
		for _, direc := range op {
			temp_x := i + direc[0]
			temp_y := j + direc[1]
			if temp_x >= 0 && temp_x < row && temp_y >= 0 && temp_y < column && !in(temp_x, temp_y, result) {
				if check(temp_x, temp_y, k+1) {
					return true
				}
			}
		}
		result[2*k], result[2*k+1] = 0, 0
		return false
	}

	for row_num := 0; row_num < row; row_num++ {
		for col_num := 0; col_num < column; col_num++ {
			if array[row_num][col_num] == s[0] && check(row_num, col_num, 0) {
				for index := 0; index < 2*n; index = index + 2 {
					fmt.Printf("%d %d\t", result[index], result[index+1])
				}
				fmt.Println()
				return true
			}
		}
	}
	fmt.Println("not found!")
	return false
}

func main() {
	case0 := [][]byte{
		{'A', 'C', 'C', 'F'},
		{'C', 'D', 'E', 'D'},
		{'B', 'E', 'S', 'S'},
		{'F', 'E', 'C', 'A'}}
	case1 := [][]byte{{'C', 'C', 'C', 'F'},
		{'C', 'D', 'E', 'D'},
		{'B', 'E', 'S', 'S'},
		{'F', 'E', 'C', 'A'}}
	case2 := [][]byte{
		{'C', 'C', 'C', 'F', 'k'},
		{'C', 'D', 'E', 'C', 'K'},
		{'B', 'M', 'F', 'O', 'D'},
		{'F', 'E', 'E', 'A', 'E'},
		{'F', 'F', 'B', 'B', 'E'}}
	case3 := [][]byte{
		{'C', 'C', 'C', 'F', 'k'},
		{'C', 'D', 'E', 'C', 'K'},
		{'B', 'M', 'D', 'O', 'D'},
		{'F', 'E', 'F', 'A', 'E'},
		{'F', 'F', 'B', 'B', 'E'}}
	find_word(case0, "ACCESS")
	find_word(case1, "ACCESS")
	find_word(case2, "DECODE")
	find_word(case3, "DECODE")
}
