func minRemoveToMakeValid(s string) string {
	ans := []byte(s)
	var stack []int
	length := 0
	for i := 0; i < len(ans); {
		if ans[i] == '(' {
			stack = append(stack, i)
			length++
		} else if ans[i] == ')' {
			if length > 0 && ans[stack[length-1]] == '(' {
				length--
				stack = stack[:length]
			} else {
				ans = append(ans[:i], ans[i+1:]...)
				continue
			}
		}
		i++
	}
	if length != 0 {
		for i := length - 1; i >= 0; i-- {
			index := stack[i]
			ans = append(ans[:index], ans[index+1:]...)
		}
	}
	return string(ans)
}

//理解了官方的思路了，这样确实好很多。
//因为只有一种小括号，所以干脆入栈括号的索引嘛，根据索引删除，简单方便还不容易出错，比起你再遍历一遍不是好得多？
//这里要注意的点在于，删除东西的时候最好是从后往前，否则很可能会下标爆炸（各种奇怪的越界）