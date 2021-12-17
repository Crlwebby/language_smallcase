func search(nums []int, target int) int {
	length := len(nums)
	for i := 0; i < length; i++ {
		if nums[i] == target {
			return i
		}
	}
	return -1
}

//不是很懂这题思路嗷，因为本身你要找到旋转点，也得平均O(N)的复杂度，我直接找也是O（N）的复杂度，那何必呢？
//还是说，二分查找支持你在部分有序的情况下查找？不会这么变态的运用吧