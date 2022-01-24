import "sort"

func findRelativeRanks(score []int) []string {
	type pair struct{ score, idx int }
	//定义结构体,type struct_variable_type struct{meber definition}
	arr := make([]pair, len(score))
	//一个和输入等长的结构体数组
	for i, v := range score {
		arr[i] = pair{v, i}
	}
	//pair{v,i}也是定义结构体变量的方式，可以直接赋值。
	sort.Slice(arr, func(i, j int) bool { return arr[i].score > arr[j].score })
	//利用sort接口，根据score元素的大小，因为返回的是大于，因此是降序排序
	res := make([]string, len(score))
	for i, v := range arr {
		if i == 0 {
			res[v.idx] = "Gold Medal"
		} else if i == 1 {
			res[v.idx] = "Silver Medal"
		} else if i == 2 {
			res[v.idx] = "Bronze Medal"
		} else {
			res[v.idx] = strconv.Itoa(i + 1)
		}
	}
	return res
}

