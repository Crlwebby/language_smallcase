func missingElement(nums []int, k int) int {
	length := len(nums)
	ans := 0
	if length == 1 {
		return nums[0] + k
	}
	for i := 1; i < length; i++ {
		delta := nums[i] - nums[i-1]
		if delta > k {
			ans = nums[i-1] + k
			break
		} else {
			k -= (delta - 1)
		}
	}
	if ans == 0 {
		ans = nums[length-1] + k
	}
	return ans
}

//这个是朴素版本，就按着题目的思路做的，也许叫复现法？好像乱七八糟有个说法的。
//想想二分怎么处理吧