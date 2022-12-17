func singleNumber(nums []int) int {
	len := len(nums)
	res := nums[0]
	for i := 1; i < len; i++ {
		res ^= nums[i]
	}
	return res
}

//想了半天怎么线性时间复杂度外加O(1)空间实现，妹想到是异或，位运算真的，yyds