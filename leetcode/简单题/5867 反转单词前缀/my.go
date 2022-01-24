func reversePrefix(word string, ch byte) string {
	temp := []byte(word)
	len := len(temp)
	index := 0
	for _, v := range temp {
		if v == ch {
			index++
			break
		} else {
			index++
		}
	}
	if index == len && word[index-1] != ch {
		return word
	}
	for i := 0; i < index; i++ {
		temp[i], temp[index-1] = temp[index-1], temp[i]
		index--
	}
	return string(temp)
}
