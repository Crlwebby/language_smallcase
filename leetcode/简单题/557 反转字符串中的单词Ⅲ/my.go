func reverseWords(s string) string {
	temp := []byte(s)
	len := len(temp)
	i, j := 0, 0
	for i < len {
		j = i + 1
		for j < len {
			if temp[j] == ' ' {
				break
			}
			j++
		}
		t := j - 1
		for i < t {
			temp[i], temp[t] = temp[t], temp[i]
			i++
			t--
		}
		i = j + 1
	}
	return string(temp)
}

//简单题我重拳出击（不是）