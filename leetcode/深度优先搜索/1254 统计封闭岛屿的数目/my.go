func closedIsland(grid [][]int) int {
	row := len(grid)
	column := len(grid[0])
	direction := [][]int{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}
	ans := 0
	flag := 0
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if i < 0 || i == row || j < 0 || j == column || grid[i][j] != 0 {
			//该岛屿有一部分与边缘接触，没有完全被1包围，标记一下不属于岛屿
			return
		}
		if i == 0 || i == row-1 || j == 0 || j == column-1 {
			flag = 1
		}
		grid[i][j] = 2
		for _, index := range direction {
			temp_x := i + index[0]
			temp_y := j + index[1]
			dfs(temp_x, temp_y)
		}
	}
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if grid[i][j] == 0 {
				flag = 0
				dfs(i, j)
				if flag == 0 {
					ans++
				}
			}
		}
	}
	return ans
}

//做确实是做出来了，但是效率好像不太理想。。。
//问题出在哪呢？这道题不是dfs吗？本身就具有N^2的遍历，然后dfs还有一些（但是不会求）
//先再复习一下时间复杂度，再看看官方有没有更好的做法。 