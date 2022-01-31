func canFinish(numCourses int, prerequisites [][]int) bool {
	graph := make([][]int, numCourses)
	for i := 0; i < numCourses; i++ {
		graph[i] = make([]int, numCourses)
	}
	//建图
	for i := 0; i < len(prerequisites); i++ {
		j, k := prerequisites[i][1], prerequisites[i][0]
		graph[j][k] = 1
	}
	//初始化边关系
	points := make([]int, numCourses)
	var queue []int
	for i := 0; i < numCourses; i++ {
		for j := 0; j < numCourses; j++ {
			points[i] += graph[j][i]
		}
		if points[i] == 0 {
			//初始化入度
			queue = append(queue, i)
		}
	}
	//初始化入度为0的队列
	for len(queue) != 0 {
		temp := queue[0]
		queue = queue[1:]
		for i := 0; i < numCourses; i++ {
			if graph[temp][i] == 1 {
				points[i]--
				if points[i] == 0 {
					queue = append(queue, i)
				}
			}
		}
	}
	fmt.Println(points)
	for i := 0; i < numCourses; i++ {
		if points[i] != 0 {
			return false
		}
	}
	return true
}

//属实是麻了233333
//拓扑排序思想还是很好理解滴！但是代码写起来就好臭好臭
//你看这若干个O(N)，也许能有优化的空间吧……