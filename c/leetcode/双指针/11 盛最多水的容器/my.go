func maxArea(height []int) int {
	length := len(height)
	i, j := 0, length-1
	ans := 0
	for i <= j {
		temp := (j - i) * min(height[i], height[j])
		ans = max(ans, temp)
		if height[i] >= height[j] {
			j--
		} else {
			i++
		}
	}
	return ans
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

//参照官方思路来的。
//第一部分还是预料之中，就是哪边比较矮移动哪边；主要是一个两边高度相等没想明白
//后来看别人讨论慢慢看明白了，因为决定容量的是较矮的那根柱子，所以两根高度一致时，无论移动哪根，容积总是会变小的；
//即使后面一直移比如左边，看着宽度不断在变小，不如刚开始移动右边
//其实还是一样的，即使移动了右边，右边高的话，容积还是左边的柱子决定的
//比如 1 2 7 2 3 4 8 10 5 3 6 9 7 5 3
//这种到两边7的位置时，即使移动右边，容积还是由左边的7决定，容积还是变小；而且最终也会到达8 10 5 3 6 9 7 的位置；
//而移动左边呢？一样的，会到达同样的位置，所以没有影响。