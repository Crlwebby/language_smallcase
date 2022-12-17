func generate(numRows int) [][]int {
	res := make([][]int, numRows)
	res[0] = append(res[0], 1)
	for i := 1; i < numRows; i++ {
		res[i] = append(res[i], 1)
		for j := 1; j < i; j++ {
			res[i] = append(res[i], res[i-1][j-1]+res[i-1][j])
		}
		res[i] = append(res[i], 1)
	}
	return res
}

//就这样吧……原本想归为动规的，发现太简单了，还是当作普通的简单题来看待吧……