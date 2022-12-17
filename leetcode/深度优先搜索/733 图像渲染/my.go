func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	row := len(image)
	column := len(image[0])
	origin := image[sr][sc]
	var visited [][]int
	for i := 0; i < row; i++ {
		temp := make([]int, column)
		visited = append(visited, temp)
	}
	direct := [][]int{{-1, 0}, {0, -1}, {0, 1}, {1, 0}}
	var dfs func(i, j int)
	dfs = func(i, j int) {
		if i < 0 || i >= row || j < 0 || j >= column || image[i][j] != origin || visited[i][j] == 1 {
			return
		}
		image[i][j] = newColor
		visited[i][j] = 1
		for _, index := range direct {
			temp_x := i + index[0]
			temp_y := j + index[1]
			dfs(temp_x, temp_y)
		}
	}
	dfs(sr, sc)
	return image
}

//常规思路，常规思路还是会做滴^^
//看看官方题解有没有更简洁一些