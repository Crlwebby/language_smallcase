func numIslands(grid [][]byte) int {
	row := len(grid)
	column := len(grid[0])
	ans := 0
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if grid[i][j] == '1' {
				ans++
				dfs(grid, i, j)
			}
		}
	}
	return ans
}

func dfs(grid [][]byte, i int, j int) {
	if i < 0 || i == len(grid) || j < 0 || j == len(grid[0]) {
		return
	}
	if grid[i][j] == '0' || grid[i][j] == '2' {
		return
	} else {
		grid[i][j] = '2'
		dfs(grid, i-1, j)
		dfs(grid, i+1, j)
		dfs(grid, i, j-1)
		dfs(grid, i, j+1)
	}
}

//这真的是清爽多了！
//我咋这么蠢呢……遍历的时候，把遍历的点改一下值，不就完了嘛！把dfs放在遍历整个矩阵里，遇见新的点再遍历，整体感觉舒服多了！