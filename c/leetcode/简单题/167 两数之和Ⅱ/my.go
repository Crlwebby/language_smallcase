func twoSum(numbers []int, target int) []int {
	answer := make([]int, 2)
	len := len(numbers)
	for i := 0; i < len; i++ {
		for j := i + 1; j < len; j++ {
			if numbers[i]+numbers[j] == target {
				answer[0] = i + 1
				answer[1] = j + 1
				break
			}
		}
		if answer[0] != answer[1] {
			break
		}
	}
	return answer
}

//咋双指针啊，暴力可以吗……直接双循环……打败5.45%的时间复杂度……