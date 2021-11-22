func maxProduct(words []string) int {
	length := len(words)
	bitnum := make([]int, length)
	res := 0
	for i, v := range words {
		word := []byte(v)
		for j := 0; j < len(word); j++ {
			bitnum[i] |= 0x1 << int(word[j]&0x1f)
		}
	}
	/*
		for i,word := range words{
	        for _, ch := range word{
	            bitnum[i] |= 1 << (ch - 'a')
	        }
	    }
	*/
	//官方的，对比一下，你就知道有多简洁了……还在这强制类型转换，还想个0x1f，未免太麻烦了……
	for i := 0; i < length; i++ {
		for j := i + 1; j < length; j++ {
			if (bitnum[i] & bitnum[j]) == 0 {
				temp := len(words[i]) * len(words[j])
				if temp > res {
					res = temp
				}
			}
		}
	}
	return res
}

//参考官方题解思想做出来的题，还行
//位运算还是个挺麻烦的事情……我觉得我这个有点脱裤子放屁的味道了=。=，位运算搞晕了，然后GO的string和byte也一直傻傻分不清楚，这可怎么办呢……