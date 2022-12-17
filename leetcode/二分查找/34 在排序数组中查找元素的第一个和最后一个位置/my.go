func searchRange(nums []int, target int) []int {
	length := len(nums)
	res := []int{-1, -1}
	if length == 0 {
		return res
	}
	i, j := 0, length-1
	mid := 0
	ans := 0
	for i <= j {
		mid = (i + j) / 2
		if nums[mid] >= target {
			j = mid - 1
			ans = mid
		} else {
			i = mid + 1
		}
	}
	if nums[ans] != target {
		return res
	}
	res[0] = ans
	res[1] = ans
	i, j = 0, length-1
	ans = 0
	for i <= j {
		mid = (i + j) / 2
		if nums[mid] > target {
			j = mid - 1
			ans = mid
		} else {
			i = mid + 1
		}
	}
	if ans > 0 && nums[ans-1] == target {
		res[1] = ans - 1
	}
	if ans == 0 {
		res[1] = length - 1
	}
	//这个边界处理挺丑陋的说实话。当你要找的值刚好是升序的最后几个时，就找不到最后一个大于target的值，此时ans肯定是0，就这样额外处理一下……
	return res
}

//我靠，居然给我过了……意料之外啊hhhhhhh
//感觉对二分查找有了点理解了。原本心态爆炸，搞不清楚到底要找哪个值，现在发现二分查找的关键不在left和right，而在于mid
//条件对了，然后记录Mid的值，管他左右到哪去了，全部遍历完了事，mid才是要保存的位置。控制好mid，就能随心所欲的按条件用二分找到需要的值，而不是在左右两个节点上绕来绕去