func rotate(nums []int, k int) {
	len := len(nums)
	k = k % len
	reverse(nums, 0, len-1)
	//fmt.Println(nums)
	reverse(nums, 0, k-1)
	//fmt.Println(nums)
	reverse(nums, k, len-1)
	//fmt.Println(nums)
}

func reverse(nums []int, start int, end int) {
	for start < end {
		nums[start], nums[end] = nums[end], nums[start]
		start++
		end--
	}
}

//还是这样写的爽~第二种办法要有观察力，三次反转数组才获得结果，没仔细观察还真想不出来
//还有一种办法太数学了，我甚至代码也没怎么看懂，感觉不想思考了，以后再说~