func tribonacci(n int) int {
	num := []int{0, 1, 1}
	if n < 2 {
		return num[n]
	}
	for i := 3; i <= n; i++ {
		temp := num[0] + num[1] + num[2]
		num[0] = num[1]
		num[1] = num[2]
		num[2] = temp
	}
	return num[2]
}