func sortedSquares(nums []int) []int {
	len := len(nums)
	res := make([]int, len)
	i := 0
	j := len - 1
	for pos := len - 1; pos >= 0; pos-- {
		v, w := nums[i]*nums[i], nums[j]*nums[j]
		if v >= w {
			res[pos] = v
			i++
		} else {
			res[pos] = w
			j--
		}
	}
	return res
}

//头昏昏沉沉，还是看题解做出来的……
//确实，这好像是归并排序的思想。就是两个区间，然后两个指针，一个个的比较，比较大的放进更新点的数组里
//长度不同的话怎么比较呢？忘了，复习下归并排序吧……用归并的思想确实很容易

//噢，看来我还是没有理解归并排序。归并排序的双指针，并不是说要判断这两个指针是否到尾部
//而是这两个指针尾部的值加起来等于n，就像这道题的len-1，然后两种情况分别移动两个指针，这样就不用判断边界了