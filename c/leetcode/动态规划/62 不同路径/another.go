func uniquePaths(m int, n int) int {
	if m < 2 {
		return 1
	}
	var dp [][]int
	for i := 0; i < 2; i++ {
		temp := make([]int, n)
		dp = append(dp, temp)
	}
	for i := 0; i < 2; i++ {
		dp[i][0] = 1
	}
	for i := 0; i < n; i++ {
		dp[0][i] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			dp[1][j] = dp[0][j] + dp[1][j-1]
			dp[0][j] = dp[1][j]
		}
	}
	return dp[1][n-1]
}

//还确实有优化的空间，我咋就那么笨呢
//就是说，我填充dp数组的时候也是这样的嘛，就一行一行扫描的。那么我需要的数据其实也就上一行和这一行的，因此多的就扔掉呗
//还有个边界条件我也是服了……这个少于两行的，让我wa了一发，可恶啊