func longestPalindrome(s string) int {
	temp := []byte(s)
	len := len(temp)
	dict := make(map[byte]int)
	for i := 0; i < len; i++ {
		if _, ok := dict[temp[i]]; ok {
			dict[temp[i]]++
		} else {
			dict[temp[i]] = 1
		}
	}
	res := 0
	flag := 0
	for _, v := range dict {
		if v%2 == 0 {
			res += v
		} else {
			res += v - 1
			flag = 1
		}
	}
	if flag == 1 {
		res++
	}
	return res
}

//参考了官方思路做的题，一口气wa了四次，针不戳……
//简单来说，原本判断字符串是否能构成回文的思路比较绕，所以面向样例编程一直错，直到官方题解的一句话点醒了我
//回文串，要么奇数要么偶数长度（废话），奇数的话要有个字符放中间，偶数就没有，并且每个字符都是偶数个。
//然后我第一反应就是哈希，记录字符个数。如果有偶数个的直接加，奇数个的减一加进去。
//但是这样bug很多，奇数个字符，全是一个字符也可以加呀。
//官方说：每次取两个。如果最后还有多的字符，随便取一个就行了。这就是我这题的思路了，还是有点长，看看题解？