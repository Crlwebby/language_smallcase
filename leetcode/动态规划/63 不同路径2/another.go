func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	row := len(obstacleGrid)
	column := len(obstacleGrid[0])
	if row < 2 {
		for i := 0; i < column; i++ {
			if obstacleGrid[0][i] == 1 {
				return 0
			}
		}
		return 1
	}
	var dp [][]int
	for i := 0; i < 2; i++ {
		dp = append(dp, make([]int, column))
	}
	for i := 0; i < 2; i++ {
		if obstacleGrid[i][0] == 1 {
			for j := i; j < 2; j++ {
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
		if obstacleGrid[i][0] == 0 && dp[0][0] == 1 {
			dp[1][0] = 1
			dp[0][0] = dp[1][0]
		} else {
			dp[1][0] = 0
			dp[0][0] = dp[1][0]
		}
		for j := 1; j < column; j++ {
			if obstacleGrid[i][j] == 1 {
				dp[1][j] = 0
				dp[0][j] = dp[1][j]
				continue
			}
			dp[1][j] = dp[0][j] + dp[1][j-1]
			dp[0][j] = dp[1][j]
		}
	}
	return dp[1][column-1]
}

//还是有那么一点不同的……这点不同让我wa了三次……
//就是说，你要压缩dp数组，就有些数据是后面还要再算的。不同路径1的时候预定义就行，不同路径2的话，由于后面有可能有石子，因而要打个补丁处理一下