func makeConnected(n int, connections [][]int) int {
	num := len(connections)
	if num < n-1 {
		return -1
	}
	ans := 0
	//记录连通块的数量，连通块数量减一即为结果；

	grid := make([][]int, n)
	//矩阵记录图关系（题目的这种输入条件我实在不太会写图算法……）
	for i := 0; i < num; i++ {
		x, y := connections[i][0], connections[i][1]
		grid[x] = append(grid[x], y)
		grid[y] = append(grid[y], x)
	}
	vis := make([]int, n)
	//记录孤立点，每个被遍历到的点都记一下，剩下的就都是一个个分开的连通块了
	queue := make([]int, n)
	start, end := 0, 0
	//用start,end 模拟队列，写队列有点麻烦
	for i := 0; i < n; i++ {
		if vis[i] == 0 {
			vis[i] = 1
			ans++
			//找到新的独立点了
			queue[end] = i
			end++
			//入队列一个元素，然后通过这个元素遍历该连通块
			for start != end {
				p := queue[start]
				start++
				for j := 0; j < len(grid[p]); j++ {
					//新点的所有邻接边，有len(grid[p])这么多
					near := grid[p][j]
					if vis[near] == 0 {
						queue[end] = near
						end++
						vis[near] = 1
					}
				}
			}
			start = 0
			end = 0
		}
	}
	return ans - 1
}

//不像是个典型的图算法题……反正我写的挺不典型的……
//但是思想还是图的思想，就是查找连通块的个数，只是理解怎么写，但又不知道怎么写成递归形式（可能我也并不明白递归）
//用邻接矩阵直接炸空间了，这里数据量大了是稀疏图，还是邻接链表好一点。