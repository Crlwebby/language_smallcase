func minRemoveToMakeValid(s string) string {
	ans := []byte(s)
	var stack []byte
	length := 0
	for i := 0; i < len(ans); {
		if ans[i] == '(' {
			stack = append(stack, '(')
			length++
		} else if ans[i] == ')' {
			if length > 0 && stack[length-1] == '(' {
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
		for i := len(ans) - 1; length > 0 && i >= 0; i-- {
			if ans[i] == '(' {
				ans = append(ans[:i], ans[i+1:]...)
				length--
			}
		}
	}
	return string(ans)
}

//说实话，感觉这样子还是有些问题……虽然通过了
//但是题目里有这样一个例子	"(a(b(c)d)" 删掉应该变成 "a(b(c)d)" , 但是我这个删法就变成了 "(a(bc)d)"
//总感觉哪里怪怪的…… 我这个算法没法记录哪两个括号匹配，因而删掉了第一个孤家寡人……就是从后往前找的第一个左括号=。=