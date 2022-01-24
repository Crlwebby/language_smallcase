func sortedArrayToBST(nums []int) *TreeNode {
	length := len(nums)
	if length == 0 {
		return nil
	}
	middle := length / 2
	ans := &TreeNode{nums[middle], nil, nil}
	if middle > 0 {
		ans.Left = sortedArrayToBST(nums[0:middle])
	} else {
		ans.Left = nil
	}
	if middle < length-1 {
		ans.Right = sortedArrayToBST(nums[middle+1 : length])
	} else {
		ans.Right = nil
	}
	return ans
}

//惭愧，还是看半年前的题解得到的思路，发现数组是有序的，取中间的直接建立就好。