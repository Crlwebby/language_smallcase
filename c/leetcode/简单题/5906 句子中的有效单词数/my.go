package main

import "fmt"

func main() {
	temp := "0"
	fmt.Println(countValidWords(temp))
}

func countValidWords(sentence string) int {
	res := 0
	nums := []byte(sentence)
	nums_len := len(nums)
	j := 0
	for i := 0; i < nums_len; i++ {
		if nums[i] == ' ' {
			if i-j > 1 && judge(nums, i, j) {
				res++
			}
			for nums[i] == ' ' {
				i++
			}
			j = i
		}
	}
	if j < nums_len && judge(nums, nums_len-1, j) {
		res++
	}
	return res
}

func is_lowcase(a byte) bool {
	if a >= 'a' && a <= 'z' {
		return true
	}
	return false
}

func judge(nums []byte, i int, j int) bool {
	t := j
	if i == j {
		if is_lowcase(nums[i]) {
			return true
		} else {
			return false
		}
	}
	for ; t < i; t++ {
		if nums[t] >= '0' && nums[t] <= '9' {
			break
		}
		if t == j && !is_lowcase(nums[t]) {
			break
		}
		if nums[t] == '-' && (!is_lowcase(nums[t-1]) || !is_lowcase(nums[t+1])) {
			break
		}
	}
	if t == i {
		return true
	}
	return false
}
