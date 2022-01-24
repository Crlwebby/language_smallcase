func minFallingPathSum(matrix [][]int) int {
	n := len(matrix)
	if n < 2 {
		return matrix[0][0]
	}
	/*res := make([]int,n)
	  for i := 0; i < n; i++{
	      res[i] = matrix[0][i]
	  }*/
	for i := 1; i < n; i++ {
		matrix[i][0] += min(matrix[i-1][0], matrix[i-1][1])
		for j := 1; j < n-1; j++ {
			matrix[i][j] = matrix[i][j] + min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1]))
		}
		matrix[i][n-1] = matrix[i][n-1] + min(matrix[i-1][n-2], matrix[i-1][n-1])
	}
	res := matrix[n-1][0]
	for i := 1; i < n; i++ {
		res = min(res, matrix[n-1][i])
	}
	return res
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

//这道题感觉和以前做过的很类似，就把之前的数据保存一下就做出来了，很简单