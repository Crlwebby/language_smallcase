func maxProfit(prices []int) int {
	len := len(prices)
	if len < 2 {
		return 0
	}
	dp := make([][2]int, len)
	dp[0][1] = -prices[0]
	dp[1][0] = max(dp[0][0], dp[0][1]+prices[1])
	dp[1][1] = max(dp[0][1], -prices[1])
	for i := 2; i < len; i++ {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
		dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])
	}
	return dp[len-1][0]
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//基本上就是和买卖股票Ⅱ一模一样的DP方程。
//我写的算是比较丑陋的，前两个DP自己进行额外的判断，还不能确定对不对。后面的应该没什么问题，因为包含冷冻期，所以下次持有应该和两天前的卖出相比较
//看了题解，发现我的属于非典型DP……因为dp[i]不是由dp[i-1]决定的，跳了一步，可能会在某些样例上出现问题
//官方的题解DP数组有三个，分别是持有、不持有、冷冻期。这种其实挺合理的，感觉所有可能都覆盖了，而不是像我这样稀里糊涂的