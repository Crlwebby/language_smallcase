func minCost(costs [][]int) int {
	dp := [3]int{costs[0][0], costs[0][1], costs[0][2]}
	length := len(costs)
	for i := 1; i < length; i++ {
		a, b, c := dp[0], dp[1], dp[2]
		dp[0] = min(costs[i][0]+b, costs[i][0]+c)
		dp[1] = min(costs[i][1]+a, costs[i][1]+c)
		dp[2] = min(costs[i][2]+a, costs[i][2]+b)
	}
	ans := dp[0]
	if ans > dp[1] {
		ans = dp[1]
	}
	if ans > dp[2] {
		ans = dp[2]
	}
	return ans
}

//芜湖，一波过~
//我最初的困惑在于，如果每个房子保存一个DP值，即最小的价值，是不是不太对？
//比如第一间房子最低A，第二间+第一间最低B，以此类推。
//后来发现这其实不太对。或者说，其实并不好计算，起码你得保存最低代价所对应的下标，然后还不一定前面最小代表加起来最小。
//后面就顺理成章了，每个房子保存三种粉刷颜色的最小，然后往后一直计算就是了，能保证不刷错而且很方便~