func fib(n int) int {
	if n < 2 {
		return n
	}
	var a = []int{0, 1}
	for i := 2; i <= n; i++ {
		a = append(a, a[i-1]+a[i-2])
	}
	return a[n]
}

//没啥说的，就是练语法了~

func fib(n int) int {
	if n < 2 {
		return n
	}
	var a = [2]int{0, 1}
	for i := 2; i <= n; i++ {
		temp := a[1]
		a[1] = a[0] + a[1]
		a[0] = temp
	}
	return a[1]
}

//另一个版本咯