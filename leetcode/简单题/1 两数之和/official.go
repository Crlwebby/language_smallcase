func twoSum(nums []int, target int) []int {
	dict := map[int]int{}
	for i, x := range nums {
		if key, value := dict[target-x]; value {
			return []int{key, i}
		}
		dict[x] = i
	}
	return nil
}

//妹想到以前做题这么原始，啥注释也没加，就嗯做？
//总之，能想到是哈希，但是哈希用的真不多，于是写的很头疼
//倒也不是说头疼，而是自己GO实在是个半吊子，看个官方题解感觉有好多未知语法……
//比如这个key,value := dict[target-x]，为什么key,value是值、布尔型的，而不是键值对呢……这个赋值就离谱