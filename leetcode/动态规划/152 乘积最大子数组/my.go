func maxProduct(nums []int) int {
	len := len(nums)
	max := make([]int, len)
	min := make([]int, len)
	max[0] = nums[0]
	min[0] = nums[0]
	for i := 1; i < len; i++ {
		max[i] = my_max(max[i-1]*nums[i], min[i-1]*nums[i], nums[i])
		min[i] = my_min(max[i-1]*nums[i], min[i-1]*nums[i], nums[i])
	}
	res := max[0]
	for i := 1; i < len; i++ {
		if max[i] > res {
			res = max[i]
		}
	}
	return res
}

func my_max(a int, b int, c int) int {
	max := a
	if b > max {
		max = b
	}
	if c > max {
		max = c
	}
	return max
}

func my_min(a int, b int, c int) int {
	min := a
	if b < min {
		min = b
	}
	if c < min {
		min = c
	}
	return min
}

//用go又写了一遍，还是不太会呀！这种分类的东西，有点小头疼。没想明白怎么处理负数，自己一看题解倒是想得明白
//想办法复述一遍思路吧
//由于负负得正的问题，某一刻乘一个负数，并不一定就要舍弃掉，在未来的某一刻它还有可能变成正数，因此要保留这个负数的可能性
//怎么保留呢？最大数肯定还是最大的，乘了负数会变成最小的数，因而还要维护个最小值的数组
//怎么确保不会有原本是负数的被你变成正数然后当作最大值了呢？
//我没有主动的给数字变正负，数字的正负关系只依赖于乘积，就是当前数字和以前数字的乘积，是最大的就放最大里去，最小的就放最小的里面去