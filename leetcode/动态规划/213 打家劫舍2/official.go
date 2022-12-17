func _rob(nums []int) int {
	len := len(nums)
	if len == 1 {
		return nums[0]
	}
	if len == 2 {
		return max(nums[0], nums[1])
	}
	first, second := nums[0], max(nums[0], nums[1])
	for _, v := range nums[2:] {
		first, second = second, max(first+v, second)
	}
	return second
}

func rob(nums []int) int {
	len := len(nums)
	if len == 1 {
		return nums[0]
	}
	if len == 2 {
		return max(nums[0], nums[1])
	}
	return max(_rob(nums[:len-1]), _rob(nums[1:]))
}

func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}

//确实巧妙，分成两个区间来算，一个是[0,n-1]，另一个是[1,n]，感觉好像中间的数据被遍历了两次，但是这东西干净呀~