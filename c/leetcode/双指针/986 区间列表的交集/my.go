func intervalIntersection(firstList [][]int, secondList [][]int) [][]int {
	len1 := len(firstList)
	len2 := len(secondList)
	var ans [][]int
	for i := 0; i < len1; i++ {
		for j := 0; j < len2; j++ {
			if firstList[i][0] > secondList[j][1] {
				continue
			}
			if firstList[i][1] < secondList[j][0] {
				break
			}
			ans = append(ans, []int{max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])})
		}
	}
	return ans
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

//直接暴力O(N^2)的解法……一次写对还算顺利吧，画图就能画出来交集的几种情况了，问题不大
//看看官方有没有优化的思路？反正我这个只剪枝了一部分，就是如果发现secondlist在firstlist右边时跳出循环，但是在左边没有交集时不知道怎么处理，所以还是O（N^2)