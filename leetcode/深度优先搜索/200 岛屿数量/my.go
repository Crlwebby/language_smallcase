func numIslands(grid [][]byte) int {
	row := len(grid)
	column := len(grid[0])
	var traverse [][]int
	var temp [][]int
	for i := 0; i < row; i++ {
		traverse = append(traverse, []int{})
		for j := 0; j < column; j++ {
			if grid[i][j] == '1' {
				temp = append(temp, []int{i, j})
			}
			traverse[i] = append(traverse[i], 0)
		}
	}
	depth := len(temp)
	length := 0
	ans := 0
	for length < depth {
		if traverse[temp[length][0]][temp[length][1]] == 0 {
			dfs(grid, traverse, temp[length][0], temp[length][1])
			ans++
		} else {
			length++
		}
	}
	return ans
}

func dfs(grid [][]byte, traverse [][]int, i int, j int) {
	if i < 0 || i == len(grid) || j < 0 || j == len(grid[0]) {
		return
	}
	if grid[i][j] == '0' || traverse[i][j] == 1 {
		return
	} else {
		traverse[i][j] = 1
		dfs(grid, traverse, i-1, j)
		dfs(grid, traverse, i+1, j)
		dfs(grid, traverse, i, j-1)
		dfs(grid, traverse, i, j+1)
	}
}

//深度优先写的总是那么的长……
//没有栈，就用一个数组记录为1的节点，然后就看见了第19、20行的鬼畜代码……
//其它的也都好理解，只不过网格上的深度优先，总是要有第30行的条件判断
//题解说的很好：先污染后治理……就是你超出边界了给你拉回来，而不是判断要不要出边界然后遍历，后面这种就很麻烦

//另一个方法也很巧妙啊！遍历过的不需要用travere数组，把1改为2即可，很棒！