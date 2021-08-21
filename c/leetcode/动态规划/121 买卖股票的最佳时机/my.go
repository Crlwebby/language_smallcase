func maxProfit(prices []int) int {
	res := 0
	min := prices[0]
	len := len(prices)
	for i := 1; i < len; i++ {
		res = max(res, prices[i]-min)
		if min > prices[i] {
			min = prices[i]
		}
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//迷迷糊糊做出来的，真的好久不学习，现在脑子跟一团浆糊一样
//简单来说，这题看起来像是动态规划，有动态规划的思想在，但更像是普通的数组题
//保存此前的价格最低的股票值，然后往后遍历，发现如果某刻卖出比现在收益高了，就更新收益