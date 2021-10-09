func fib(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	num := make([]int, 2)
	num[0] = 0
	num[1] = 1
	for i := 2; i <= n; i++ {
		temp := num[0] + num[1]
		num[1], num[0] = temp, num[1]
	}
	return num[1]
}

//斐波那契还是好写，确实没啥说的。。。