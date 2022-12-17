func lengthOfLIS(nums []int) int {
	len := len(nums)
	dp := make([]int, len)
	res := 0
	for i := 0; i < len; i++ {
		dp[i] = 1
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				dp[i] = max(dp[j]+1, dp[i])
			}
		}
		res = max(res, dp[i])
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//参考别人答案的=。=，一旦看明白递推公式，写代码就是顺理成章的事情了……原本想的也是好像要n^2，要么想想怎么优化一下？
//第一重循环肯定是没法避免的，你肯定要分析完全部的内容。关键就是第二个，如果在已遍历完的数组中找到最合适的那个，然后更新当前dp的值？
//