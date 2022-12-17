func backspaceCompare(s string, t string) bool {
	len1, len2 := 0, 0
	str1 := make([]byte, 200)
	str2 := make([]byte, 200)
	for _, ch := range s {
		str1[len1] = byte(ch)
		len1++
		if ch == '#' {
			if len1 >= 2 {
				len1 = len1 - 2
			} else {
				len1 = len1 - 1
			}
		}
	}
	for _, ch := range t {
		str2[len2] = byte(ch)
		len2++
		if ch == '#' {
			if len2 >= 2 {
				len2 = len2 - 2
			} else {
				len2 = len2 - 1
			}
		}
	}
	if len1 != len2 {
		return false
	}
	for i := 0; i < len1; i++ {
		if str1[i] != str2[i] {
			return false
		}
	}
	return true
}

//蠢蠢做法，就先把实际的字符串先打印出来，然后再比较，大概是O（2*(M+N))的时间吧，而且空间复杂度也一样