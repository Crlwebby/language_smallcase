func uniquePaths(m int, n int) int {
	var dp [][]int
	for i := 0; i < m; i++ {
		temp := make([]int, n)
		dp = append(dp, temp)
	}
	for i := 0; i < m; i++ {
		dp[i][0] = 1
	}
	for i := 0; i < n; i++ {
		dp[0][i] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
		}
	}
	return dp[m-1][n-1]
}

//感觉跟跳楼梯一样的，第一感觉就有了递推公式hhhhhh，做的最简单的一道DP了
//就是golang的定义二维数组给我弄得有那么点头疼。你要说它是个特性多的语言吧，动态数组（变量定义数组长度）也不支持
//你要说它是比较基础的语言吧，又不用自己分配空间，总之就是各种觉得怪异，不出所料，内存消耗2.1MB，超过8.73%……拉跨了
//看看别人怎么搞，这个应该没法只维护两个变量吧？