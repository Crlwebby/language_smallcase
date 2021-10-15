func maxProfit(prices []int, fee int) int {
	len := len(prices)
	dp := make([][2]int, len)
	dp[0][0] = -prices[0]
	for i := 1; i < len; i++ {
		dp[i][0] = max(dp[i-1][1]-prices[i], dp[i-1][0])
		dp[i][1] = max(dp[i-1][0]+prices[i]-fee, dp[i-1][1])
		fmt.Println(dp[i][0], dp[i][1])
	}
	return dp[len-1][1]
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//说是说自己写的，但是实际上还是参考买卖股票Ⅱ的官方答案然后写的。
//就是不是很理解，为什么这样一个状态转移方程，就能计算出来正确的结果呢？
//按照贪心的策略，肯定是记录所有上升期的收益，然后进行一个判断（零手续费的情况下）
//而按照DP的思路来说，记录下降的地方在于dp[i][0]。就是某天股票价格很高，你持有了，发现收益下降了，还不如继续持有原来的，那么今天的就不持有。
//这样好像还蛮好理解的？因为即使以后能涨的更高，那也是以前的低价买入的股票收益更高，而不是今天高价买入的股票。
//同样的，当你发现某天卖出的股票，减去手续费以后发现收益还降了，那也是不如继续持有而不卖出。