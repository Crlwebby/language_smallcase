func minimumTotal(triangle [][]int) int {
	n := len(triangle)

	for i := 1; i < n; i++ {
		triangle[i][0] += triangle[i-1][0]
		column := len(triangle[i])
		for j := 1; j < column-1; j++ {
			triangle[i][j] = triangle[i][j] + min(triangle[i-1][j], triangle[i-1][j-1])
		}
		triangle[i][column-1] = triangle[i][column-1] + triangle[i-1][column-2]
	}
	res := triangle[n-1][0]
	for i := 1; i < len(triangle[n-1]); i++ {
		res = min(res, triangle[n-1][i])
	}
	return res
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

//....没啥好说的……做了那个下降路径最小和再做这道题，感觉一模一样
//虽然没有和官方的自底向上DP一样，但是自顶向下一样简单啊……感觉边界条件都好像没有，就直接过了