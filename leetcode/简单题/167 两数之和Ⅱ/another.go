func twoSum(numbers []int, target int) []int {
	answer := make([]int, 2)
	len := len(numbers)
	i, j := 0, len-1
	for i < j {
		if numbers[i]+numbers[j] == target {
			break
		} else if numbers[i]+numbers[j] > target {
			j--
		} else {
			i++
		}
	}
	answer[0], answer[1] = i+1, j+1
	return answer
}

//确实还是简单题，官方提示：利用上升序数组的性质，感觉就明白怎么做了
//升序的，往中间慢慢微调就行了。当然，感觉可能还是有哪里不对劲，还没有合理的证明算法的正确与否
