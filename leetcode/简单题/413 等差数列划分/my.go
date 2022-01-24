func numberOfArithmeticSlices(nums []int) int {
	if len(nums) < 3 {
		return 0
	}
	gap := nums[1] - nums[0]
	num := 1
	result := 0
	for i := 2; i < len(nums); i++ {
		if nums[i]-nums[i-1] == gap {
			num++
		} else {
			gap = nums[i] - nums[i-1]
			result += num * (num - 1) / 2
			num = 1
		}
	}
	result += num * (num - 1) / 2
	return result
}

//简单粗暴，一波带走的中等题，满足感一下子就上来了哈哈哈哈哈
//简单说下思路吧。就是等差数列嘛，后面那个和前面那个的差值是不变的。然后维持这个gap，统计具有相同gap的元素有多少，就能计算这组等差数列有几个了
//gap不同时就收回，再进行下一组。以此往复