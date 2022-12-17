func minPairSum(nums []int) int {
	sort.Ints(nums)
	n := len(nums)
	result := nums[0] + nums[n-1]
	i, j := 1, n-2
	for i <= j {
		temp := nums[i] + nums[j]
		if temp > result {
			result = temp
		}
		i++
		j--
	}
	return result
}

//一道简单题……原理还不是很懂，但就直觉感觉是这个样子，排序以后 头尾相加取最大的……
//反证法应该可以证明~