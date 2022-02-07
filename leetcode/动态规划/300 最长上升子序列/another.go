func lengthOfLIS(nums []int) int {
	length := len(nums)
	dp := make([]int, length)
	max_len := 1
	dp[0] = nums[0]
	for i := 1; i < length; i++ {
		if nums[i] > dp[max_len-1] {
			dp[max_len] = nums[i]
			max_len++
		} else {
			l, r := 0, max_len-1
			mid := (l + r) / 2
			for l < r {
				if dp[mid] < nums[i] {
					l = mid + 1
				} else {
					r = mid
				}
				mid = (l + r) / 2
			}
			dp[mid] = nums[i]
		}
	}
	return max_len
}

//反正就是一笔糊涂账=。=，东改改西改改，最后还是死在二分上。
//某个大佬的二分讲得挺好的。关注点在mid，mid会把序列分成左右两个区间。考察一下哪个区间不可能存在答案，然后修改边界；
//这个思路感觉很清楚的