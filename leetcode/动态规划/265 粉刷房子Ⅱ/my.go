const INT_MAX = int(^uint(0) >> 1)

func minCostII(costs [][]int) int {
	n := len(costs)
	k := len(costs[0])
	if n == 1 {
		return slice_min(costs[0])
	}
	for i := 1; i < n; i++ {
		for j := 0; j < k; j++ {
			a := slice_min(costs[i-1][:j])
			b := slice_min(costs[i-1][j+1 : k])
			costs[i][j] += min(a, b)
		}
		fmt.Println(costs)
	}
	return slice_min(costs[n-1])
}

func slice_min(a []int) int {
	if len(a) <= 0 {
		return INT_MAX
	}
	ans := a[0]
	for i := 1; i < len(a); i++ {
		if ans > a[i] {
			ans = a[i]
		}
	}
	return ans
}

//感觉思路是有的，但是一提交就寄了，260ms，估计又是啥n^2的复杂度了吧。
//基本还是参考着粉刷1的思路。就是记录所有颜色粉刷方式的最小值。
//噢，明白为什么时间这么长了。每一次寻找上一行的最小值都是o(n)，找完一行是o(n^2)，所有房子刷完就是k*n^2了。
//还是记录最小值和次小值以及对应下标好了。每次只找一次！