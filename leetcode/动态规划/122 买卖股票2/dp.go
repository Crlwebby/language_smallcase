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

//2022.01.26	我以前这么猛吗^^，现在普通答案都没想出来
//我不是很能理解DP思路，原因在于不理解为什么这样子的DP方程是正确的。
//按照算导的思想，DP要找最优子结构，然后根据最优子结构刻画动态方程，再初始化变量，然后递归求解结果。
//问题就在这里，这道题的最优子结构我不是很明白=。=
//到某一天为止，股票的最大利润为，前一天卖出股票时的利润，或者前一天持有、今天卖出时的利润。
//好像很有道理，，，那这题就说得通了……