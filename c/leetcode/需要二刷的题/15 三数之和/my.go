func threeSum(nums []int) [][]int {
	len := len(nums)
	var res [][]int
	if len < 3 {
		return nil
	}
	dict := make(map[int][][]int)
	for i := 0; i < len; i++ {
		for j := i + 1; j < len; j++ {
			dict[nums[i]+nums[j]] = append(dict[nums[i]+nums[j]], []int{nums[i], nums[j]})
		}
	}
	for i := 0; i < len; i++ {
		if _, ok := dict[-nums[i]]; ok {
			for _, j := range dict[-nums[i]] {
				fmt.Println(j)
			}
			break
		}
	}
	return res
}

//我的想法时，先O(n^2)计算两数之和，并把输对记录进哈希表内，然后再遍历一遍原数组，在哈希里看有没有对应的相反数数对，有的话输出
//这样的问题在于有重复，而且不知道怎么处理。如果把哈希表所映射的二维切片再排序一下然后去重，感觉代价未免太高了一点，应该有更加巧妙的方法的