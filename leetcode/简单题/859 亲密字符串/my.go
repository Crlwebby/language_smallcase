func buddyStrings(s string, goal string) bool {
	length := len(s)
	if length != len(goal) {
		return false
	}
	if s == goal {
		seen := [26]bool{}
		for _, ch := range s {
			if seen[ch-'a'] {
				return true
			}
			seen[ch-'a'] = true
		}
		return false
	}
	left, right := -1, -1
	for i := 0; i < length; i++ {
		if s[i] != goal[i] {
			if left == -1 {
				left = i
			} else if right == -1 {
				right = i
			} else {
				return false
			}
		}
	}
	if right == -1 {
		return false
	}
	if s[left] == goal[right] && s[right] == goal[left] {
		return true
	}
	return false
}

//就这样吧……和官方题解思路还是比较一致的，就是有这样一个样例：两个字符串完全相同，通过一次变换还是本身，觉得有点无聊=。=
//简单题嘛，还想怎样嘛……