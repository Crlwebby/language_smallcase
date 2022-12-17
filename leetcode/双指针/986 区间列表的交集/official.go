func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
	len1 := len(firstList)
	len2 := len(secondList)
	var ans [][]int
	i, j := 0, 0
	for i < len1 && j < len2 {
		low := max(firstList[i][0], secondList[j][0])
		high := min(firstList[i][1], secondList[j][1])
		if low <= high {
			ans = append(ans, []int{low, high})
		}
		if firstList[i][1] < secondList[j][1] {
			i++
		} else {
			j++
		}
	}
	return ans
}

//(把max和min删了，以后不复制了，重复代码看得心烦)
//官方还是厉害的啊，剪枝用的很好
//首先是判断是否相交这个点上，比我的少了两个判断，更加简洁易懂。画图可以看得出来，如果两条线段没有交点，那么左端点的最大值大于右端点的最小值，以此来判断就很舒服了
//其次是左边剪枝的问题，官方提出一个末端点的概念。而且利用上了题目中给出的条件：区间列表不相交，那么一个末端点就只会最多与一个区间相交
//以这个性质来推理，就能把左边的部分也剪掉，到达O（M+N）的时间复杂度，很棒！