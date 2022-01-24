func canJump(nums []int) bool {
	len := len(nums)
	res := make([]bool, len)
	res[len-1] = true
	for i := len - 2; i >= 0; i-- {
		j := 1
		for j <= nums[i] {
			if i+j >= len {
				res[i] = false
				break
			}
			if res[i+j] == true {
				res[i] = true
				break
			}
			j++
		}
	}
	return res[0]
}

//自己的思路是，从后往前DP（算是DP吗……）
//最后一个肯定是true，然后后面往前遍历能跳到的每一格，看看有没有是true的，有的话把当前的也改成true，再继续向前推，直到初始位置
//但是运行效果很不理想，感觉像是N^2的复杂度……肯定哪里条件没利用上，或者自己想复杂了