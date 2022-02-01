func maxSumAfterOperation(nums []int) int {
	length := len(nums)
	ans := 0
	origin, handled := 0, 0
	for i := 0; i < length; i++ {
		a, b := origin, handled
		origin = max(a+nums[i], nums[i])
		handled = max(max(a+nums[i]*nums[i], b+nums[i]), nums[i]*nums[i])
		ans = max(handled, ans)
	}
	return ans
}

//基本上思路是比较吻合的，就是漏了些情况。
//先是边界条件，这点因为是求和，所以可以设初始条件为0，然后从数组0下标开始，就不用考虑单个内容的特殊情况了。
//另一个是动态方程有点不对，选择某个数进行平方的时候，可能前面已经用过了（第二个），可能前面没用过（第一个），或者选择当前数重新开始(第三个)
//我就是第三个条件没想到，然后炸了好一波=。= 毕竟还是平方数嘛，平方总归有变数的，突然变得非常大的可能性，要考虑到呀！
