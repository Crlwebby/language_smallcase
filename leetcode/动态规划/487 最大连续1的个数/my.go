func findMaxConsecutiveOnes(nums []int) int {
	ans := 0
	length := len(nums)
	if length == 1 {
		return 1
	}
	if length == 2 {
		if nums[0] == 0 && nums[1] == 0 {
			return 1
		} else {
			return 2
		}
	}
	var dp []int
	temp := 0
	for i := 0; i < length; i++ {
		if nums[i] == 1 {
			temp++
		} else {
			if temp == 0 {
				dp = append(dp, 0)
			} else {
				dp = append(dp, temp, 0)
				temp = 0
			}
		}
	}
	if temp != 0 {
		dp = append(dp, temp)
		temp = 0
	}
	length = len(dp)
	if length == 1 {
		return dp[0]
	}
	for i := 1; i < len(dp)-1; i++ {
		if dp[i] == 0 {
			ans = max(ans, dp[i-1]+dp[i+1]+1)
		}
	}
	return ans

}

//蚌埠住了呀hhhhhhh 这解题好难看
//后面都先不要看！你就看4-13行的，对边界的处理，就知道这思路肯定不太行
//我这算是O（N）吧？就一遍扫描，统计每一段1的数量，生成一个新的数组，然后在新数组里处理问题。
//新数组中有若干个0，那么统计这个0左右1的个数，再+1，然后取最值，就是要的结果了。
//感觉不算很有问题，但是方法有点愚鲁，不够灵巧