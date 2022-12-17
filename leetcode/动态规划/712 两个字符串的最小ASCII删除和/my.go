func minimumDeleteSum(s1 string, s2 string) int {
	src := []byte(s1)
	dest := []byte(s2)
	row := len(src)
	column := len(dest)
	var dp [][]int
	for i := 0; i <= row; i++ {
		temp := make([]int, column+1)
		dp = append(dp, temp)
	}
	for i := 1; i <= row; i++ {
		dp[i][0] += dp[i-1][0] + int(src[i-1])
	}
	for i := 1; i <= column; i++ {
		dp[0][i] += dp[0][i-1] + int(dest[i-1])
	}
	//初始化DP数组；
	for i := 1; i <= row; i++ {
		for j := 1; j <= column; j++ {
			if src[i-1] == dest[j-1] {
				dp[i][j] = dp[i-1][j-1]
			} else {
				dp[i][j] = min(dp[i-1][j]+int(src[i-1]), dp[i][j-1]+int(dest[j-1]))
			}
		}
	}
	fmt.Println(dp)
	return dp[row][column]
}

//折磨，看思路看了半天=。=
//时间复杂度空间复杂度也都爆表了，下次遇见再修改
//总而言之，啥也不想说。这个思想不是三言两语能够说清楚的，要多练多思考；
//两个长的字符串很难处理，两个短一些的不就好弄一点了吗？
//比如A字符串和B字符串的结果已经有了，那么要么A往后加个字符，要么B往后加个字符，然后根据这个字符的情况进行处理，这不是很容易吗？
//于是这样迭代，比如abcde和bcedf的匹配。就是a串和b\bc\bcd\...的匹配，结果出来后再计算ab和上述的匹配，最后扩展到两个字符串的完整匹配。