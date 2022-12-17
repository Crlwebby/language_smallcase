func nthUglyNumber(n int) int {
	var res []int
	res = append(res, 1, 2, 3, 4, 5)
	num2 := 2
	num3 := 2
	num5 := 4
	for i := 5; i < n; i++ {
		temp, flag := min(res[1]*res[num2], res[2]*res[num3], res[4]*res[num5])
		if temp == 0 {
			i--
		} else {
			res = append(res, temp)
		}
		if flag == 1 {
			num2++
		} else if flag == 2 {
			num3++
		} else {
			num5++
		}
	}
	return res[n-1]
}

func min(a int, b int, c int) (int, int) {
	if a == b {
		return 0, 1
	}
	if a == c {
		return 0, 1
	}
	if b == c {
		return 0, 2
	}
	temp := a
	flag := 1
	if b < temp {
		temp = b
		flag = 2
	}
	if c < temp {
		temp = c
		flag = 3
	}
	return temp, flag
}

//写得稀碎，丑陋无比……
//主要是，我没有能想到更好的，去遍历丑数的思想。动态方程感觉写不出来，只能2、3、5不断的去乘新的数字，然后比较最小的一个，这也蛮怪的……
//而且还有个flag去判断数字是否重复了……很懵逼，这不应该是这道题的正确结果，太麻烦了