func addBinary(a string, b string) string {
	var result string = ""
	carry := 0
	a_len := len(a)
	b_len := len(b)
	n := max(a_len, b_len)

	for i := 0; i < n; i++ {
		if i < a_len {
			carry += int(a[a_len-i-1] - '0')
		}
		if i < b_len {
			carry += int(b[b_len-i-1] - '0')
		}
		result = strconv.Itoa(carry%2) + result
		carry /= 2
	}
	if carry > 0 {
		result = "1" + result
	}

	return result
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

//就是抄的官答~当做熟悉Go语法了~反正二进制字符串相加也不是什么难的事情，处理进位就好了
//即使是用C语言 进位也就多一位，字符串申请个大一点的就行了