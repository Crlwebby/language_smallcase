func restoreArray(adjacentPairs [][]int) []int {
	n := len(adjacentPairs) + 1
	hash := make(map[int][]int, n)

	for _, p := range adjacentPairs {
		v, w := p[0], p[1]
		hash[v] = append(hash[v], w)
		hash[w] = append(hash[w], v)
	}

	result := make([]int, n)
	for e, p := range hash {
		if len(p) == 1 {
			result[0] = e
			break
		}
	}
	result[1] = hash[result[0]][0]

	for i := 2; i < n; i++ {
		temp := hash[result[i-1]]
		if result[i-2] == temp[0] {
			result[i] = temp[1]
		} else {
			result[i] = temp[0]
		}
	}
	return result
}

//抄的官方答案，虽然也还算好理解吧……
//主要是，第一时间想不到哈希这个。用哈希确实方便。
//相邻元素对，那肯定只有头和尾只出现一次，随便拿一个当头就行了，就是12-15行做的事情
//有了头了，怎么寻找接下来的相邻元素呢？我觉得这里给result[1]赋个值还是挺巧妙的
//众所周知，敲代码要处理边界问题，这里考虑的边界就是一个元素的左右相邻元素，头元素是没有左边的相邻的，所以要从1开始
//1有了左相邻，根据1为键查找哈希里存储的相邻元素，然后和原本的相邻比较下，看塞进去哪个合适，然后继续遍历，就O(n)了