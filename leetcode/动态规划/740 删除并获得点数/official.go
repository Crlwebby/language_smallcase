func deleteAndEarn(nums []int) int {
	maxVal := 0
	for _, v := range nums {
		maxVal = max(v, maxVal)
	}
	sum := make([]int, maxVal+1)
	for _, v := range nums {
		sum[v] += v
	}
	first, second := sum[0], max(sum[0], sum[1])
	for i := 2; i <= maxVal; i++ {
		first, second = second, max(first+sum[i], second)
	}
	return second
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//官方题解确实简洁明了，不考虑中间漏不漏的情况，统一定义一个桶，类似桶排的思想放进去就可以了。不需要的都定义为零，岂不美哉