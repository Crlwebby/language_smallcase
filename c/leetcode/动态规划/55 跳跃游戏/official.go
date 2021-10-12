func canJump(nums []int) bool {
	len := len(nums)
	rightmost := 0
	for i := 0; i < len; i++ {
		if i <= rightmost {
			rightmost = max(i+nums[i], rightmost)
		} else {
			return false
		}
		if rightmost >= len {
			return true
		}

	}
	return true
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//官方思路，贪心算法，感觉思路都比较类似，就是捋没捋清楚的问题。没弄清楚就是我那个倒着来恶心人的题解，弄清楚了就是这个很顺畅的题解。