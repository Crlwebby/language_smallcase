func search(nums []int, target int) int {
	start := 0
	end := len(nums) - 1
	mid := (start + end) / 2
	for start <= end {
		if nums[mid] == target {
			break
		} else if nums[mid] > target {
			end = mid - 1
		} else {
			start = mid + 1
		}
		mid = (start + end) / 2
	}
	if nums[mid] != target {
		return -1
	}
	return mid
}

//没啥说的