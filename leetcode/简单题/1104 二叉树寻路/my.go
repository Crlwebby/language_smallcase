func pathInZigZagTree(label int) []int {
	result := []int{1}
	if label == 1 {
		return result
	}
	level := 1
	num := []int{1}
	temp := []int{label}
	for num[level-1] <= label {
		temp = append(temp, temp[level-1]/2)
		num = append(num, num[level-1]*2)
		level += 1
	}
	sort.Ints(temp)
	for i := 2; i < level; i++ {
		if (level-1-i)%2 == 1 {
			result = append(result, num[i-1]+num[i]-1-temp[i])
		} else {
			result = append(result, temp[i])
		}
	}
	return result
}

//一道数学题，稍微有那么一丢丢折磨人？反正思想还是挺简单的，就是陷入bug时比较头疼，想明白了就好做了