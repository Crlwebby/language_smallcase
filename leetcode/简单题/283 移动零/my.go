func moveZeroes(nums []int) {
	temp := 0
	i, j := 0, len(nums)-1
	for i < j {
		if nums[i] == 0 {
			temp = nums[i]
			for t := i + 1; t <= j; t++ {
				nums[t-1] = nums[t]
			}
			nums[j] = temp
			j--
			continue
		}
		i++
	}
	return
}

//有没有办法每次不移动整个数组呢？