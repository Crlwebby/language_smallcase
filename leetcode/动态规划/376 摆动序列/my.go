func wiggleMaxLength(nums []int) int {
	n := len(nums)
	if n < 2 {
		return n
	}
	up := make([]int, n)
	down := make([]int, n)
	up[0] = 1
	down[0] = 1
	for i := 1; i < n; i++ {
		if nums[i] > nums[i-1] {
			up[i] = down[i-1] + 1
			down[i] = down[i-1]
		} else if nums[i] < nums[i-1] {
			up[i] = up[i-1]
			down[i] = up[i-1] + 1
		} else {
			up[i] = up[i-1]
			down[i] = down[i-1]
		}
	}
	return max(up[n-1], down[n-1])
}

//感觉官方题解有点绕了，DP方程没写对。
//懒得去缩减成O（1）的空间了，反正很快的，就定义临时变量用一下就行。
//这个DP为什么是正确的？因为它考虑了每一种状态转移的可能性，始得up[i]和down[i]不断地在迭代找到最长的序列。
//每一次的尾部上升，必然是上一次的尾部下降+1，这就保证了up[i]=down[i-1]+1的正确性。