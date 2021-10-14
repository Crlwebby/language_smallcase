func maxProfit(prices []int) int {
	len := len(prices)
	res := 0
	before := 0
	for i := 1; i < len; i++ {
		if prices[i] <= prices[i-1] {
			if i != before+1 {
				res += prices[i-1] - prices[before]
			}
			before = i
		}
	}
	if before != len-1 {
		res += prices[len-1] - prices[before]
	}
	return res
}

//我怎么把它归到简单题里去了……虽然看着确实还算简单，但是思考过程蛮头疼的啊
//就跟那个蓄水的题目比较类似吧。要找转折点。如果某个地方股票价格下降了，那就把它之前的收益计算一下。
//当然有条件处理，一个是连续下跌就不要计算收益了23333，另一个是最后一天还在涨，就在最后一天把股票卖掉计算一个收益