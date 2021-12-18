func findPeakElement(nums []int) int {
	length := len(nums)
	if length == 1 || nums[0] > nums[1] {
		return 0
	}
	if nums[length-1] > nums[length-2] {
		return length - 1
	}
	i, j := 1, length-2
	ans := 0
	for i <= j {
		ans = (i + j) / 2
		if nums[ans] > nums[ans-1] && nums[ans] > nums[ans+1] {
			return ans
		} else if nums[ans] > nums[ans-1] {
			i = ans + 1
		} else {
			j = ans - 1
		}
	}
	return ans
}

//思路看完一遍就懂了，就是说，数字越大的，越有可能是峰值（比两边相邻的都大）
//那么就进行二分查找；如果当前mid不是峰值，那么继续往更大的一边找（不是峰值的话肯定有更大的一边嘛），这样下去肯定找得到；
//无非是处理两个边界点，0和length-1的位置稍微麻烦一点