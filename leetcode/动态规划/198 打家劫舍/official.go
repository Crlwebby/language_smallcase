func rob(nums []int) int {
	len := len(nums)
	if len == 1 {
		return nums[0]
	} else if len == 2 {
		return max(nums[0], nums[1])
	}
	//max(i) = max(max(i-2)+v[i],max(i-1))
	//偷前一家，这家不能偷；或者前一家没偷，偷这一家。
	first, second := nums[0], max(nums[0], nums[1])
	for _, v := range nums[2:] {
		first, second = second, max(first+v, second)
	}
	return second
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//这个语法更清爽，尤其是只用两个变量存DP。其实还是挺好理解的，这个DP方程只参考前两个元素，两个变量确实够了