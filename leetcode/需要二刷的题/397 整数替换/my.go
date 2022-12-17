func integerReplacement(n int) int {
	if n == 1 {
		return 0
	}
	if n%2 == 0 {
		return integerReplacement(n/2) + 1
	} else {
		//return min(integerReplacement(n+1), integerReplacement(n-1)) + 1
		return min(integerReplacement(n/2), integerReplacement(n/2+1)) + 2
		//这个是题解的，似乎挺好的。因为+1 -1后必然变成偶数，再除个2，这俩动作是连贯的，用n/2和n/2 + 1直接一次到位就行。
		//而且这样也不会让2^32-1 + 1溢出int的范围。
	}
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

//惊喜啊哈哈哈哈哈哈，这为什么没超时啊……
//数据范围n是2^31-1欸
//没看明白为什么没超时……我把递归树打印出来也寄了啊，5000大小的数，往下就递归七百层了。。。。