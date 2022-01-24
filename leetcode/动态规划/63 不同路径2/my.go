func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	row := len(obstacleGrid)
	column := len(obstacleGrid[0])
	var dp [][]int
	for i := 0; i < row; i++ {
		dp = append(dp, make([]int, column))
	}
	for i := 0; i < row; i++ {
		if obstacleGrid[i][0] == 1 {
			for j := i; j < row; j++ {
				dp[j][0] = 0
			}
			break
		}
		dp[i][0] = 1
	}
	for i := 0; i < column; i++ {
		if obstacleGrid[0][i] == 1 {
			for j := i; j < column; j++ {
				dp[0][j] = 0
			}
			break
		}
		dp[0][i] = 1
	}
	for i := 1; i < row; i++ {
		for j := 1; j < column; j++ {
			if obstacleGrid[i][j] == 1 {
				dp[i][j] = 0
				continue
			}
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
		}
	}
	return dp[row-1][column-1]
}

//区别不大，就是有障碍物的位置特殊处理一下，就OK了
//接下来想想办法怎么优化空间吧……