func findPoisonedDuration(timeSeries []int, duration int) int {
    ans := duration * len(timeSeries)

	until := 0
	//until是每次中毒后持续到的结束时间
	//n是下一次的开始时间
	for _, n := range timeSeries {
	//_,n是获取range返回的键-值对，因为不需要键（数组下标），所以用下划线代替为空
		if n < until {
			ans -= (until - n)
		}
		until = n + duration
	}
	return ans
}

作者：derek-64
链接：https://leetcode-cn.com/problems/teemo-attacking/solution/findpoisonedduration-by-derek-64/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。