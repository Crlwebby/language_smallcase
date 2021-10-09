import "sort"

func containsDuplicate(nums []int) bool {
	len := len(nums)
	sort.Ints(nums)
	for i := 1; i < len; i++ {
		if nums[i] == nums[i-1] {
			return true
		}
	}
	return false
}

//有排序库实现真快乐