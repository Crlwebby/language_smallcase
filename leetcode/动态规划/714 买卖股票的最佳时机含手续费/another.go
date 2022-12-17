func maxProfit(prices []int, fee int) int {
	len := len(prices)
	dp := make([][2]int, 2)
	dp[0][0] = -prices[0]
	for i := 1; i < len; i++ {
		dp[1][0] = max(dp[0][0], dp[0][1]-prices[i])
		dp[1][1] = max(dp[0][1], dp[0][0]+prices[i]-fee)
		dp[0][0], dp[0][1] = dp[1][0], dp[1][1]
	}
	return dp[1][1]
}

//线性DP，经典优化一下空间