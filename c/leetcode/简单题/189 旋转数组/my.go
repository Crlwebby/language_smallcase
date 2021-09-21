func rotate(nums []int, k int) {
	len := len(nums)
	k = k % len
	k = len - k
	temp := make([]int, len)
	for i := 0; i < len; i++ {
		temp[i] = nums[i]
	}
	for i := 0; i < len; i++ {
		nums[i] = temp[(i+k)%len]
	}

}

//错了好多次……使用额外数组确实很简单，题目说有三种做法，学一学？
//