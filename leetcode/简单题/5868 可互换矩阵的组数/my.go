func interchangeableRectangles(rectangles [][]int) int64 {
	len := len(rectangles)
	m := make(map[float64]int64)
	for i := 0; i < len; i++ {
		m[float64(rectangles[i][0])/float64(rectangles[i][1])]++
	}
	var res int64 = 0
	for _, v := range m {
		res += v * (v - 1) / 2
	}
	return res
}

//就用了字典这个东西，还是挺方便的。
//如果字典要自己实现，那应该是medium题……用字典感觉更像是easy