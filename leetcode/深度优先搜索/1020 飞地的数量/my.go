func numEnclaves(grid [][]int) int {
	row := len(grid)
	column := len(grid[0])
	//direct := [][]int{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}
	flag := 0
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i < 0 || i == row || j < 0 || j == column || grid[i][j] != 1 {
			return 0
		}
		res := 1
		grid[i][j] = 2
		if i == 0 || i == row-1 || j == 0 || j == column-1 {
			flag = 1
		}
		res += dfs(i, j-1) + dfs(i, j+1) + dfs(i-1, j) + dfs(i+1, j)
		return res
	}
	ans := 0
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if grid[i][j] == 1 {
				flag = 0
				temp := dfs(i, j)
				if flag == 0 {
					ans += temp
				}
			}
		}
	}
	return ans
}

//=。= 感觉有点上当了，这不是图的计划吗，怎么只有DFS……