func findMin(nums []int) int {
	length := len(nums)
	if nums[0] < nums[length-1] {
		return nums[0]
	}
	i, j := 0, length-1
	mid := (i + j) / 2
	ans := nums[mid]
	for i <= j {
		mid = (i + j) / 2
		if ans > nums[mid] {
			ans = nums[mid]
		}
		if nums[mid] >= nums[i] {
			if ans > nums[i] {
				ans = nums[i]
			}
			i = mid + 1
		} else {
			j = mid - 1
		}
	}
	return ans
}

//和33题很像很像，一点变型而已。
//同样的，还是之前的结论。只要把mid用好，二分查找其实真的很简单很简单
//把mid存储一个值，然后看左右的情况进行分类的判断；
//如果左边有序，那么左边的最左边值肯定是最小的，比较一下看看；
//如果左边无序，最小值肯定在左边（因为旋转的地方肯定是最小值），那么右边移过来缩小范围就行了。