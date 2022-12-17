func integerReplacement(n int) int {
	dp := make(map[int]int)
	traverse(n, dp)
	return dp[n]
}
func traverse(n int, dp map[int]int) int {
	if n == 1 {
		return 0
	}
	if n%2 == 0 {
		if v, ok := dp[n/2]; ok {
			dp[n] = v + 1
			return v + 1
		}
		temp := traverse(n/2, dp) + 1
		dp[n] = temp
	} else {
		left, right := 0, 0
		if v, ok := dp[n+1]; ok {
			left = v
		} else {
			left = traverse(n+1, dp)
		}
		if v, ok := dp[n-1]; ok {
			right = v
		} else {
			right = traverse(n-1, dp)
		}
		dp[n] = min(left, right) + 1
	}
	return dp[n]
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

//做着做着还是做成了动态规划……这个是自顶向下带备忘录的动态规划……
//虽然代码比较难看，但是思想还是在的。觉得还算OK