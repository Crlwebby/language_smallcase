func maxAreaOfIsland(grid [][]int) int {
	row := len(grid)
	column := len(grid[0])
	var dfs func(i, j int) int
	direct := [][]int{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}
	dfs = func(i, j int) int {
		if i < 0 || i == row || j < 0 || j == column || grid[i][j] != 1 {
			return 0
		}
		res := 1
		grid[i][j] = 2
		for _, index := range direct {
			temp_x := i + index[0]
			temp_y := j + index[1]
			res += dfs(temp_x, temp_y)
		}
		return res
	}
	ans := 0
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if grid[i][j] == 1 {
				temp := dfs(i, j)
				if temp > ans {
					ans = temp
				}
			}
		}
	}
	return ans
}

//这种dfs刷得还是比较熟了，还是蛮简单的。
//问题就在于非常规的dfs，比如不是很直观的搜索，这种搜索如何转换成dfs统一的迭代、回溯的方法，还是比较麻烦的