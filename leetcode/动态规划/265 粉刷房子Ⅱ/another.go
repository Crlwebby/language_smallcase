const INT_MAX = int(^uint(0) >> 1)

func minCostII(costs [][]int) int {
	n := len(costs)
	k := len(costs[0])
	if n == 1 {
		_, ans := slice_min(costs[0])
		return ans[0]
	}
	for i := 1; i < n; i++ {
		before, after := slice_min(costs[i-1])
		for j := 0; j < k; j++ {
			if j == after[1] {
				costs[i][j] += before[0]
			} else {
				costs[i][j] += after[0]
			}
		}
	}
	_, ans := slice_min(costs[n-1])
	return ans[0]
}

func slice_min(a []int) ([]int, []int) {
	before := []int{INT_MAX, -1}
	after := []int{INT_MAX, -1}
	if len(a) <= 0 {
		return before, after
	}
	after[0], after[1] = a[0], 0
	for i := 1; i < len(a); i++ {
		if after[0] > a[i] {
			before[0], before[1] = after[0], after[1]
			after[0], after[1] = a[i], i
		} else if before[0] > a[i] {
			before[0], before[1] = a[i], i
		}
	}
	return before, after
}

//好绕，但是做出来了，效率8ms，nice!
//简单说来，算法的核心是怎么在O（n)的时间内找一个序列的最小值和次小值
//如果每次把最小值变更的赋予次小值，只能保证	序列次小值在最小值前面这种情况下，是成立的
//例如 9 11 5 3 6 8 10	最小值发现3比它小，然后把5赋给次小，是能成立的；但是如果次小在3后面，那就捕获不到了。
//于是后面继续遍历，如果比次小小，就把它获取到。
//有了最小和次小，粉刷就是顺理成章的事情了。如果上一个同颜色房子价格最低，那就取次小；如果不同颜色，那就直接相加。