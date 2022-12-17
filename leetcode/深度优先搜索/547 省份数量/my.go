func findCircleNum(isConnected [][]int) int {
	n := len(isConnected)
	ans := 0
	traverse := make([]int, n)
	for i := 0; i < n; i++ {
		if traverse[i] == 0 {
			ans++
			dfs(isConnected, traverse, i)
		}
	}
	return ans
}

func dfs(isConnected [][]int, traverse []int, i int) {
	for j := 0; j < len(isConnected[0]); j++ {
		if isConnected[i][j] == 1 && traverse[j] == 0 {
			traverse[j] = 1
			dfs(isConnected, traverse, j)
		}
	}

}

//不知道咋说，就感觉好简单……