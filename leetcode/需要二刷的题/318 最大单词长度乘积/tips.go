for i, x := range masks {
	for j, y := range masks[:i] {
		if x&y == 0 && len(words[i])*len(words[j]) > ans {
			ans = len(words[i]) * len(words[j])
		}
	}
}

//=.= 这是题解的，关于二重循环遍历的部分。我说为什么内部循环不能用masks[i:]
//这是官方设陷阱…………
//是这样的，切片如果取部分的话，用range，就会导致j的下标和原本的下标不一致。比如j,y := range mask，j=0对应的就是mask[0]
//但是如果用mask[i:]，那j=0对应的是mask[i]，怪不得变了之后怎么改怎么不对。。。