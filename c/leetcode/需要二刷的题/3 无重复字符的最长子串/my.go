func lengthOfLongestSubstring(s string) int {
	len := len(s)
	i, j := 0, 0
	dict := make([]int, 128)
	max := 0
	temp := 0
	for j < len {
		if dict[s[j]] == 0 {
			temp++
			dict[s[j]] = 1
			j++
		} else {
			dict[s[i]] = 0
			i++
			temp--
		}
		max = max1(max, temp)
	}
	return max
}

func max1(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//想起来怎么做了，就还算简单^.^ 用128的切片当字典，反正是字符串嘛……放得下
//然后滑动窗口yyds，做起来还是很方便滴