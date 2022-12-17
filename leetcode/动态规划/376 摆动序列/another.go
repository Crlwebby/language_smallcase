func wiggleMaxLength(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}
	ans := 0
	if nums[0] == nums[1] {
		ans = 1
	} else {
		ans = 2
	}
	prediff := nums[1] - nums[0]
	for i := 2; i < n; i++ {
		diff := nums[i] - nums[i-1]
		if diff > 0 && prediff <= 0 || diff < 0 && prediff >= 0 {
			ans++
			prediff = diff
		}
	}
	return ans
}

//贪心，统计峰和谷的个数，关键在于保存前面是上升还是下降的信息，这里用的是prediff保存的。
//注意Prediff更新时机。不能每次循环都更新，一定要保存上次成功记录的信息，否则会在3557这种序列时，给出错误的答案