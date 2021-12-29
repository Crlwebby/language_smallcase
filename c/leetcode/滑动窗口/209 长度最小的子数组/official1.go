func minSubArrayLen(s int, nums []int) int {
	n := len(nums)
	if n == 0 { //边界处理：长度为零。但实际上这题给了数据范围，长度不为零……
		return 0
	}
	ans := math.MaxInt32
	//因为要找最小的，所以先预设一个MaxInt，常规操作；
	sums := make([]int, n+1)
	// 为了方便计算，令 size = n + 1
	// sums[0] = 0 意味着前 0 个元素的前缀和为 0
	// sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
	// 以此类推
	for i := 1; i <= n; i++ {
		sums[i] = sums[i-1] + nums[i-1]
	}
	//前缀和的思想很棒，这里还用了动规的思想来求前缀和
	//sum[j]-sum[i]，即为i到j-1的区间和；sum[j] = 求和（0->j-1) sum[i]=求和(0->i-1)，这段长度为j-i，一切都很配合这道题。
	for i := 1; i <= n; i++ {
		target := s + sums[i-1]
		bound := sort.SearchInts(sums, target)
		if bound < 0 {
			bound = -bound - 1
		}
		if bound <= n {
			ans = min(ans, bound-(i-1))
		}
	}
	if ans == math.MaxInt32 {
		return 0
	}
	return ans
}

//1.