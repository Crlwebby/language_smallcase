func probabilityOfHeads(prob []float64, target int) float64 {
	length := len(prob)
	dp := make([][]float64, 2)
	for i := 0; i < 2; i++ {
		//初始化二维DP数组；
		temp := make([]float64, target+1)
		dp[i] = append(dp[i], temp...)
	}

	dp[0][0] = 1

	for i := 1; i <= length; i++ {
		dp[1][0] = dp[0][0] * (1 - prob[i-1])
		for j := 1; j <= target; j++ {
			dp[1][j] = dp[0][j-1]*prob[i-1] + dp[0][j]*(1-prob[i-1])
		}
		for j := 0; j <= target; j++ {
			dp[0][j], dp[1][j] = dp[1][j], dp[0][j]
		}
		//fmt.Println(dp[1])
	}
	return dp[0][target]
}

//优化一下空间