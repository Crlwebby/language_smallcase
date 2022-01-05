func isHappy(n int) bool {
	m := map[int]bool{}

	for n != 1 && !m[n] {
		//如果某个数字是遍历过的，说明存在环，就不可能变为1了；
		m[n] = true
		n = step(n)
	}
	return n == 1
}

func step(n int) int {
	sum := 0
	for n > 0 {
		sum += (n % 10) * (n % 10)
		n = n / 10
	}
	return sum
}

//一大早就在抄题解……
//题解的思想真的很妙呀，这是个数学题！根本没这种想法