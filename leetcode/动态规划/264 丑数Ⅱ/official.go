func nthUglyNumber(n int) int {
	res := make([]int, n+1)
	res[1] = 1
	num2 := 1
	num3 := 1
	num5 := 1
	for i := 2; i <= n; i++ {
		p1, p2, p3 := 2*res[num2], 3*res[num3], 5*res[num5]
		res[i] = min(p1, min(p2, p3))
		if res[i] == p1 {
			num2++
		}
		if res[i] == p2 {
			num3++
		}
		if res[i] == p3 {
			num5++
		}
	}
	return res[n]
}

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

//标答还是猛的呀！
//说实话我脑子有点绕了，题解的思路很清晰，每次都是2x 3x 5x中取最小的数字加进res数组去，然后移动指针
//这个思路老实说是差不多的，只不过题解直接用2、3、5，我在那用res[xxx]的，很麻烦；
//还有就是如何去重这件事情，很巧妙。如果刚好某两个指针使得2x1 = 3x2了，那么把其中一个加进去，然后两个都往后遍历就行
//不用你记录什么flag，记录到底是哪两个数相等，这太绕了。思路还是没有转变为更加适合编程的简洁的思路呀