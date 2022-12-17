func minDistance(word1 string, word2 string) int {
	l1 := []byte(word1)
	l2 := []byte(word2)
	len1 := len(l1)
	len2 := len(l2)
	var dp [][]int
	for i := 0; i <= len1; i++ {
		//多保存一位，0字符到0字符的修改为0，所以要保存长度为len+1
		temp := make([]int, len2+1)
		dp = append(dp, temp)
	}
	for i := 0; i <= len1; i++ {
		dp[i][0] = i
	}
	for i := 0; i <= len2; i++ {
		dp[0][i] = i
	}
	for i := 1; i <= len1; i++ {
		for j := 1; j <= len2; j++ {
			increase := dp[i][j-1] + 1
			decrease := dp[i-1][j] + 1
			modify := dp[i-1][j-1]
			if l1[i-1] != l2[j-1] {
				//i,j是DP数组的下标，实际上是要比字符串大一位的
				//dp[i][j]表示的是l1[:i-1]到l2[:j-1]的编辑距离，这个列个矩阵就能很明显的看出来
				//      0   r   o   s
				//  0
				//  h       1，1
				//  o
				//  r
				//  s
				//  e
				//dp[1][1]代表的是l1[0]和l2[0]的关系；
				modify++
			}
			//为什么不用比较整个字符串，只要上一位相等，就不用修改（斜着方向直接继承上次的值）？
			//因为我们假设前面都已经编辑过了，所有可能的结果也都列入在DP方程内了；
			dp[i][j] = min(increase, min(decrease, modify))
		}
	}
	fmt.Println(dp)
	return dp[len1][len2]
}

//看得有点头晕=。=
//总感觉有哪些点没有想明白，还是有问题，但是算法是对的
//就是动态规划还不够直观吧，自己的脑子还没能模拟出动规的过程，所以有点搞不明白
