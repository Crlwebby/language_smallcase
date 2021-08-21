func maxSubArray(nums []int) int {
	res := nums[0]
	len := len(nums)
	temp := nums[0]
	for i := 1; i < len; i++ {
		temp = max(temp+nums[i], nums[i])
		res = max(res, temp)

	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//最简单的动态规划，递推公式一下子看出来了……应该是做过的原因吧，第一次没写出来的