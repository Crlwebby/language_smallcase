import "sort"

func findRelativeRanks(score []int) []string {
	dict := make(map[int]int)
	temp := make([]int, len(score))
	copy(temp, score)
	sort.Sort(sort.Reverse(sort.IntSlice(temp)))
	i := 1
	for _, v := range temp {
		dict[v] = i
		i++
	}
	res := []string{}
	for _, v := range score {
		if dict[v] == 1 {
			res = append(res, "Gold Medal")
		} else if dict[v] == 2 {
			res = append(res, "Silver Medal")
		} else if dict[v] == 3 {
			res = append(res, "Bronze Medal")
		} else {
			res = append(res, strconv.Itoa(dict[v]))
		}
	}
	return res
}

//啰嗦了不少，还用了下字典。
//主要是，还是很不习惯于使用结构体（？还算个程序员吗），然后就额外维护变量来做这道题
//strconv.Itoa还确实没用过，一直在考虑怎么把int变为unicode型的string，没想到是这样搞的，大意了