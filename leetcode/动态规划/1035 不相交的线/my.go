func maxUncrossedLines(nums1 []int, nums2 []int) int {
	row := len(nums1)
	column := len(nums2)
	var dp [][]int
	for i := 0; i <= row; i++ {
		temp := make([]int, column+1)
		dp = append(dp, temp)
	}

	for i := 1; i <= row; i++ {
		for j := 1; j <= column; j++ {
			if nums1[i-1] == nums2[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	//fmt.Println(dp)
	return dp[row][column]
}

//和上一道一样，二维DP，还行~