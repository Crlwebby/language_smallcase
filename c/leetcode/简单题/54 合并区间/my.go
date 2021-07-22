func merge(intervals [][]int) [][]int {
	less := func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	}
	sort.Slice(intervals, less)
	var result [][]int
	temp := intervals[0]
	for i := 0; i < len(intervals); i++ {
		temp[0] = intervals[i][0]
		temp[1] = intervals[i][1]
		var j int
		for j = i + 1; j < len(intervals); j++ {
			if intervals[j][0] > temp[1] {
				break
			}
			if intervals[j][1] > temp[1] {
				temp[1] = intervals[j][1]
			}
		}
		result = append(result, []int{temp[0], temp[1]})
		if j == len(intervals) {
			break
		}
		i = j - 1
	}

	return result
}

//就就，调了下bug，然后不知道go语言二维切片怎么添加元素，其它没啥了。这题确实还挺简单的~