func maxScoreSightseeingPair(values []int) int {
	len := len(values)
	res := 0
	mx := values[0]
	for i := 1; i < len; i++ {
		res = max(res, mx+values[i]-i)
		mx = max(mx, values[i]+i)
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//爷不配…………自己想只能想到暴力，一点思路没有。
//看了题解发现把题目条件组合一下，就能使用单个变量遍历全部可能性，太妙了