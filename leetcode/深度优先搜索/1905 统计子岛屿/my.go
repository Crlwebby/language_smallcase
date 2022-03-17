func countSubIslands(grid1 [][]int, grid2 [][]int) int {
	//题目能更变态一点，但是那个时候可能就真的很变态了……就是岛屿支持翻转，也就是全等(?!)，就是i,j不相等，但有可能包含的情况，这估计有点牵扯数学了=。=
	row := len(grid2)
	column := len(grid2[0])
	flag := 0
	//grid2的岛屿不被grid1包含时，用flag做一个标记，此岛屿不记录；
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if i < 0 || i >= row || j < 0 || j >= column || grid2[i][j] != 1 {
			return
		}
		if grid1[i][j] != 1 {
			flag = 1
		}
		grid2[i][j] = 2
		dfs(i, j+1)
		dfs(i, j-1)
		dfs(i-1, j)
		dfs(i+1, j)
	}
	ans := 0
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if grid2[i][j] == 1 {
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

//okok…… 这深搜一道比一道简单。。。还是练DP练的比较痛苦