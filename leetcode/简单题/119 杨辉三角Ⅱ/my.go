func getRow(rowIndex int) []int {
	res := make([]int, rowIndex+1)
	for i := 0; i <= rowIndex; i++ {
		res[i] = 1
	}
	for i := 2; i <= rowIndex; i++ {
		temp := 1
		for j := 1; j < i; j++ {
			temp, res[j] = res[j], temp
			res[j] = res[j] + temp
		}
	}
	return res
}

//题目不算难，就是怎么用一个数组进行原地操作有一丢丢绕，想明白了还是很简单的