func isHappy(n int) bool {
	slow, fast := n, n
	for {
		slow = step(slow)
		fast = step(fast)
		fast = step(fast)
		if slow == fast {
			break
		}
	}
	return slow == 1
	//slow是一个一个遍历的，不会跳过1，fast有可能跳过1
}

func step(n int) int {
	sum := 0
	for n > 0 {
		sum += (n % 10) * (n % 10)
		n = n / 10
	}
	return sum
}

//双指针判环，秒啊，这题的本质被看透了……
