func findLHS(nums []int) int {
	dict := make(map[int]int)
	sort.Ints(nums)
	length := len(nums)
	res := 0
	for i := 0; i < length; {
		j := i
		for j < length && nums[j] == nums[i] {
			j++
		}
		dict[nums[i]] = j - i
		i = j
	}
	for key, val := range dict {
		if v, ok := dict[key+1]; ok {
			res = max(res, v+val)
		}
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//奇奇怪怪的做出来的，完全依赖于字典……比题解长了很多，还是用哈希偷懒做的，滑动窗口有那么亿点点麻烦，晚点再学一下看看
//