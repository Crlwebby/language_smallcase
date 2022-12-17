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

//大概明白什么是最优子结构了。动态规划不能随心写，要用最优子结构证明动态方程的正确性。
//一个长为n的数组，前k个的最大和必然是n最大和的一部分吗？