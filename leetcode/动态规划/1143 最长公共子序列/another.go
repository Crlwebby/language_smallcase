func longestCommonSubsequence(text1 string, text2 string) int {
	src := []byte(text1)
	dest := []byte(text2)
	len1 := len(src)
	len2 := len(dest)
	dp := make([][]int, len1+1)
	for i := 0; i <= len1; i++ {
		temp := make([]int, len2+1)
		dp[i] = temp
	}
	for i := 1; i <= len1; i++ {
		for j := 1; j <= len2; j++ {
			if src[i-1] == dest[j-1] {
				//数组扩大了一圈，但是原本的字符串长度没变，会越界。
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j])
			}
		}
	}
	return dp[len1][len2]
}

//完全参照着官方题解写的……
//二维DP，感觉思路虽然好理解，但是想不到。从来就没有把两个字符串当成一个矩阵然后去对比的思想=。=