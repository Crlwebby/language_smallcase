func moveZeroes(nums []int) {
	left, right := 0, 0
	len := len(nums)
	for right < len {
		if nums[right] != 0 {
			nums[left], nums[right] = nums[right], nums[left]
			left++
		}
		right++
	}
	return
}

//双指针真是用处多多呀，这样写 学到了