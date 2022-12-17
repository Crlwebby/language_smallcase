func climbStairs(n int) int {
	if n == 1 {
		return 1
	}
	num := []int{1, 2}
	for i := 3; i <= n; i++ {
		temp := num[0] + num[1]
		num[0] = num[1]
		num[1] = temp
	}
	return num[1]
}

//爬楼梯在动规里讲解好多次了，都不用自己想递推式=。=