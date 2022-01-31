func canFinish(numCourses int, prerequisites [][]int) bool {
	var (
		edges = make([][]int, numCourses)
		//没毛病，图关系肯定要保存的。
		visited = make([]int, numCourses)
		//visited数组和我的points比较相像
		result []int
		valid  = true
		dfs    func(u int)
	)

	dfs = func(u int) {
		visited[u] = 1
		for _, v := range edges[u] {
			if visited[v] == 0 {
				dfs(v)
				if !valid {
					return
				}
			} else if visited[v] == 1 {
				valid = false
				return
			}
		}
		visited[u] = 2
		result = append(result, u)
	}

	for _, info := range prerequisites {
		edges[info[1]] = append(edges[info[1]], info[0])
	}
	//info[1] -> info[0] 在info[1]中保存info[0]，构建图
	//等等，这个好像是邻接表表示法，不是邻接矩阵
	for i := 0; i < numCourses && valid; i++ {
		if visited[i] == 0 {
			dfs(i)
		}
	}
	return valid
}

//官方题解，虽然用的是DFS，但是DFS在拓扑排序中本质上是一样的。
//DFS也需要用队列保存遍历节点，也要构建图关系、建立visited数组，和记录入度为0的是很像的。
//我应该仔细看看，同样的方法，效率千差万别，原因何在？