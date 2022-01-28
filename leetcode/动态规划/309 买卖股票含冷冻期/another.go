func maxProfit(prices []int) int {
	len := len(prices)
	dp := make([][3]int, 3)
	//dp[i][0]代表持有
	//dp[i][1]代表非冷冻期,未持有
	//dp[i][2]代表冷冻期，未持有
	dp[0][0] = -prices[0]
	fmt.Println(dp[0][0], dp[0][1], dp[0][2])
	for i := 1; i < len; i++ {
		dp[1][0] = max(dp[0][0], dp[1][1]-prices[i])
		dp[1][1] = max(dp[0][1], dp[0][2])
		//状态转移到非冷冻期有两种，一种是昨天是冷冻期，另一种是昨天就已经是非冷冻期。
		dp[1][2] = dp[0][0] + prices[i]
		dp[0][0], dp[0][1], dp[0][2] = dp[1][0], dp[1][1], dp[1][2]
	}
	return max(dp[1][1], dp[1][2])
}

//理解了三个变量就好说。更新了点思路，感觉比之前思考的顺畅了