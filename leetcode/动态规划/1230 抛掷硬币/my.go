func probabilityOfHeads(prob []float64, target int) float64 {
	length := len(prob)
	dp := make([][]float64, length+1)
	for i := 0; i <= length; i++ {
		//初始化二维DP数组；
		temp := make([]float64, target+1)
		dp[i] = append(dp[i], temp...)
	}

	dp[0][0] = 1
	for i := 1; i <= length; i++ {
		dp[i][0] = dp[i-1][0] * (1 - prob[i-1])
	}
	//起始量初始化

	for i := 1; i <= length; i++ {
		for j := 1; j <= target; j++ {
			dp[i][j] = dp[i-1][j-1]*prob[i-1] + dp[i-1][j]*(1-prob[i-1])
		}
	}
	//fmt.Println(dp)
	return dp[length][target]
}

//二维DP确实没怎么遇见过，搞懵逼了
//二维DP也是要确定状态是如何转移的，以及定义初始化变量，这俩对了后面一切都是顺理成章的。