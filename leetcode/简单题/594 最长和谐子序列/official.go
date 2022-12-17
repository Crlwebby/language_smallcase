func findLHS(nums []int) int {
	dict := make(map[int]int)
	res := 0
	for _, v := range nums {
		dict[v]++
	}
	for key, val := range dict {
		if v, ok := dict[key+1]; ok {
			if v+val > res {
				res = v + val
			}
		}
	}
	return res
}

//改进版本的哈希吧，将就着看看……	