func majorityElement(nums []int) int {
	len := len(nums)
	dict := make(map[int]int)
	for i := 0; i < len; i++ {
		if _, ok := dict[nums[i]]; ok {
			dict[nums[i]]++
		} else {
			dict[nums[i]] = 1
		}
	}
	for i, v := range dict {
		if v > len/2 {
			return i
		}
	}
	return 0
}

//第一反应就是哈希，也就当练一下GO语法？效果不尽人意
//先是_,ok := dict[]这种形式，ok所获取的只是true 或者false，不是for range语法中的键、值，这个点要注意；
//其他算法没看明白……就觉得排序后取中间数和分治思想挺可取的，投票算法和概率算法有点复杂……