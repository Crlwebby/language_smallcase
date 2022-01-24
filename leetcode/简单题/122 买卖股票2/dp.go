func maxProfit(prices []int) int {
	len := len(prices)
	dp0, dp1 := 0, 0
	dp1 = -prices[0]
	for i := 1; i < len; i++ {
		newdp0 := max(dp1+prices[i], dp0)
		newdp1 := max(dp0-prices[i], dp1)
		dp0 = newdp0
		dp1 = newdp1
	}
	return dp0
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//dp思路，还是很舒服的~什么时候能学会这该死的DP啊！！