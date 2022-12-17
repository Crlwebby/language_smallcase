func maxProfit(prices []int) int {
	len := len(prices)
	dp := make([][3]int, len)
	//dp[i][0]代表持有
	//dp[i][1]代表非冷冻期,未持有
	//dp[i][2]代表冷冻期，未持有
	dp[0][0] = -prices[0]
	for i := 1; i < len; i++ {
		dp[i][0] = max(dp[i-1][1]-prices[i], dp[i-1][0])
		dp[i][1] = max(dp[i-1][1], dp[i-1][2])
		dp[i][2] = dp[i-1][0] + prices[i]
	}
	return max(dp[len-1][1], dp[len-1][2])
}

//这个好难……三个DP方程搞在一起，让我即使看了一遍题解，也很难写出来，还是边看题解边写的
//三个状态实在是，太绕了。冷冻期和非冷冻期代表的到底是什么含义呢？
//冷冻期是卖出后的第一天，非冷冻期是卖出后的若干天；有可能这若干天都是跌的，那就一直是非冷冻期，但是也不买？
//不想理解了……三个状态真的，好麻烦好麻烦

//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/fei-zhuang-tai-ji-de-dpjiang-jie-chao-ji-tong-su-y/
//这个人的思路是比较好懂的，建议学习，讲解的很清楚。虽然还是不能手动模拟状态转移的过程，但是对这道题有了更深的理解（大概
