func maxDistance(grid [][]int) int {
	row := len(grid)
	column := len(grid[0])
	ans := -1
	const INT_MAX = int(^uint(0) >> 1)
	var visited [][]int
	for i := 0; i < row; i++ {
		temp := make([]int, column)
		visited = append(visited, temp)
	}
	var point [][]int
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if grid[i][j] == 1 {
				point = append(point, []int{i, j})
			}
		}
	}
	//point记录所有的大陆坐标，比起bfs再找一圈还是要快那么一点点的=。=
	if len(point) == 0 {
		return -1
	}
	//如果没有大陆，直接寄，返回-1
	var findNearestLand func(i, j int) int
	findNearestLand = func(i, j int) int {
		ans := INT_MAX
		for _, index := range point {
			ans = min(ans, distance(i, j, index[0], index[1]))
		}
		//从所有大陆里计算下距离，找到最小的，然后返回
		return ans
	}

	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if grid[i][j] == 0 {
				a := findNearestLand(i, j)
				ans = max(ans, a)
			}
		}
	}

	return ans
}

func clear(a [][]int) {
	row := len(a)
	column := len(a[0])
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			a[i][j] = 0
		}
	}
}
func distance(x0, y0 int, x1, y1 int) int {
	res := 0
	if x0 < x1 {
		res += x1 - x0
	} else {
		res += x0 - x1
	}
	if y0 < y1 {
		res += y1 - y0
	} else {
		res += y0 - y1
	}
	return res
}

//有点蚌埠住了，1108ms，这还是我修改了官方题解的结果……这就是愚蠢算法吗。。。
//为什么修改呢？因为官方题解寄了，超时了。。。
//反正最烂的思路是一致的，就是找到所有的海洋到大陆的距离，然后取最小。
//这样写思路反而比bfs清晰……我再看看其它思路吧，1108ms实在是受不了了