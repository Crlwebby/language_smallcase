func rob(nums []int) int {
	len := len(nums)
	if len == 1 {
		return nums[0]
	} else if len == 2 {
		return max(nums[0], nums[1])
	}
	dp := make([]int, len)
	dp[0] = nums[0]
	dp[1] = max(nums[0], nums[1])
	for i := 2; i < len; i++ {
		dp[i] = max(dp[i-1], dp[i-2]+nums[i])
	}
	return dp[len-1]
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//确实，做过一遍的DP，感觉思想很简单23333，语法写的比以前简洁了一丢丢，其它没啥说的