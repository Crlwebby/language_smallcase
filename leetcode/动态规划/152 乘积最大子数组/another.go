func maxProduct(nums []int) int {
	len := len(nums)
	max := make([]int, 2)
	min := make([]int, 2)
	max[0] = nums[0]
	min[0] = nums[0]
	res := max[0]
	for i := 1; i < len; i++ {
		max[1] = my_max(max[0]*nums[i], min[0]*nums[i], nums[i])
		min[1] = my_min(max[0]*nums[i], min[0]*nums[i], nums[i])
		if res < max[1] {
			res = max[1]
		}
		max[0] = max[1]
		min[0] = min[1]
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

//优化了一下空间~也是常规思路了。就看状态转移方程需要多少个状态，只维护这些状态就可以了