func maxProfit(prices []int) int {
	max := 0
	index := prices[0]
	len := len(prices)
	for i := 1; i < len; i++ {
		if prices[i] < prices[i-1] {
			max += prices[i-1] - index
			index = prices[i]
		}
	}
	if prices[len-1] > index {
		max += prices[len-1] - index
	}
	return max
}

//还行，像是智力题