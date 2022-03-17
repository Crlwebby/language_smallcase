func pacificAtlantic(heights [][]int) [][]int {
	row := len(heights)
	column := len(heights[0])
	var answer [][]int
	var visited [][]int
	//var atlantic [][]int
	for i := 0; i < row; i++ {
		temp := make([]int, column)
		visited = append(visited, temp)
	}
	var dfs func(i, j, key int)
	dfs = func(i, j, key int) {
		if i < 0 || i == row || j < 0 || j == column || visited[i][j]&key != 0 {
			//key用1表示太平洋可以流经，用2表示大西洋可以流经
			//1和2分别是01和10，因而用与运算不冲突，可以判断是否曾经遍历过，01 与 01和11想与都不为零，说明都遍历过；
			return
		}
		visited[i][j] += key
		if visited[i][j] == 3 {
			answer = append(answer, []int{i, j})
		}
		if i-1 >= 0 && heights[i-1][j] >= heights[i][j] {
			dfs(i-1, j, key)
		}
		if i+1 < row && heights[i+1][j] >= heights[i][j] {
			dfs(i+1, j, key)
		}
		if j-1 >= 0 && heights[i][j-1] >= heights[i][j] {
			dfs(i, j-1, key)
		}
		if j+1 < column && heights[i][j+1] >= heights[i][j] {
			dfs(i, j+1, key)
		}
	}
	for j := 0; j < column; j++ {
		dfs(0, j, 1)     //从上到下
		dfs(row-1, j, 2) //从下到上
	}
	for i := 0; i < row; i++ {
		dfs(i, 0, 1)        //从左到右
		dfs(i, column-1, 2) //从右到左
	}
	return answer
}

//属实是看不明白了。。。
//好复杂哇！这个dfs值得学习，我还玩了个臊皮的位运算=。=，节省了点空间
//总之就是逆向的思考，水往高处流，从四条边开始dfs，找到比自己高的陆地，那它的水肯定可以流向海洋。