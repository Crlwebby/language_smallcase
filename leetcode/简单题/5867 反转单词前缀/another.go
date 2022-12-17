func reversePrefix(s string, ch byte) string {
	j := strings.IndexByte(s, ch)
	if j < 0 {
		return s
	}
	t := []byte(s)
	for i := 0; i < j; i++ {
		t[i], t[j] = t[j], t[i]
		j--
	}
	return string(t)
}

作者：endlesscheng
链接：https://leetcode-cn.com/problems/reverse-prefix-of-word/solution/go-mo-ni-by-endlesscheng-tq1p/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//这是大佬的题解
//第一行就等于我的前十四行吧，就是查找ch在字符串中的位置；
//if判断有没有，然后后面局部反转，思路比较像
