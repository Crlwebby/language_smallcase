func minCostClimbingStairs(cost []int) int {
	len := len(cost)
	if len == 1 {
		return cost[0]
	}
	num := []int{cost[0], cost[1]}
	for i := 2; i < len; i++ {
		temp := min(num[0]+cost[i], num[1]+cost[i])
		num[0] = num[1]
		num[1] = temp
	}
	return min(num[0], num[1])
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

//真的，垃圾题
//题目表述是真的不清楚，看麻了