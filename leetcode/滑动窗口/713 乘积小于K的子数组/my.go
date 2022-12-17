func numSubarrayProductLessThanK(nums []int, k int) int {
	length := len(nums)
	product := 1
	//保存乘积，由于选择双指针，乘积最大不会超过k，因此不会溢出，不需要取对数
	ans := 0
	//统计数组个数
	i, j := 0, 0
	for j < length {
		product *= nums[j]
		for i <= j && product >= k {
			product /= nums[i]
			i++
		}
		ans += j - i + 1
		//相当于从j的位置开始取数组，取一个、两个、三个，直到j-i+1个
		//比如[10,5,2,6],i=1,j=3的时候，满足条件的数组就是[6] [6,2] [6,2,5]三个
		//为什么[2]和[5]和[2,5]不取呢？因为说了，是从j的位置开始向前取，在i=1,j=2的时候，[2],[2,5]都是取过的；在j=1的时候，[5]是取过的
		//所有的都在此前某一次取到了，因而现在只取一部分就好了；
		j++
	}
	return ans
}

//这道题基本上酸是照着抄的……
//