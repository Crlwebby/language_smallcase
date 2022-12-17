func maxPower(s string) int {
	res := 1
	length := len(s)
	start := 0
	for i := 1; i < length; i++ {
		if s[i] != s[start] {
			res = max(i-start, res)
			start = i
		}
	}
	if start != length-1 {
		res = max(length-start, res)
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//好蠢的题