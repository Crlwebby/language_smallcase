func searchInsert(nums []int, target int) int {
	len := len(nums)
	start := 0
	end := len - 1
	var mid int
	for start <= end {
		mid = (start + end) / 2
		if nums[mid] >= target {
			end = mid - 1
		} else {
			start = mid + 1
		}
	}
	return left
}

//天哪，比以前还蠢了？看上次代码写的，就那么三四行，现在怎么回事嘛……
//重新理解下，二分查找插入位置，本质上是找第一个大于等于target的值（或者小于等于应该也可以）
//无非是等号放在的位置不一样。但是这两种情况下，最后返回的值应该有所不同
//left < target < right,当right=left+1时，mid=left，此时如果nums[mid]刚好大于target，那插入位置就是left和mid；
//如果nums[mid]小于target，下一次left=right=mid，此时nums[mid]>=target，判断语句里会把等号所在的值改变一下，该返回的也就是另一边的值
//left=right的情况下，如果nums[mid]<target，那应该往后一位插入，就是left+1，也就是left；如果nums[mid]>target，插入位置是right,那也是left；
//所以，最后返回的值，在升序的情况下应该是left，降序才是right
