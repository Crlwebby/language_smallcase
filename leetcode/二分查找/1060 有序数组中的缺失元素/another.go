func missingElement(nums []int, k int) int {
	length := len(nums)
	ans := 0
	if length == 1 {
		return nums[0] + k
	}
	i, j, mid := 0, length-1, 0
	for i <= j {
		mid = (i + j) / 2
		delta := (nums[mid] - nums[0]) - (mid - 0)
		if delta >= k {
			j = mid - 1
		} else {
			i = mid + 1
		}
	}
	mid = (i + j) / 2
	ans = nums[mid] + (k - (nums[mid] - nums[0]) + (mid - 0))
	return ans
}

//咳咳，难看是难看了那么亿点点，但是总归是做对的。
//果然，二分查找还是要找一个递增数组，就是每个Nums[i]缺失的数字个数，通过这个东西我们可以得到二分查找的依据
//当然，不限制O（logn)的话会更好，这里的第10行、第18行本质上也是在算那个数字，重复计算总归是让人很不爽的，倒不如一次遍历全部记录下来