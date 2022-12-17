func rob(nums []int) int {
	dp := make([]int, 2)
	if len(nums) == 1 {
		return nums[0]
	} else if len(nums) == 2 {
		return max(nums[0], nums[1])
	} else {
		dp[0] = nums[0]
		dp[1] = max(nums[0], nums[1])
	}
	for i := 2; i < len(nums); i++ {
		temp := max(dp[i-1], dp[i-2]+nums[i])
		dp = append(dp, temp)
	}
	//fmt.Println(dp)
	return dp[len(nums)-1]
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//还行，算简单题吧，动态方程还好写、好理解的