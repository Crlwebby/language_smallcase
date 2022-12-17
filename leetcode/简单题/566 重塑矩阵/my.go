func matrixReshape(mat [][]int, r int, c int) [][]int {
	row, column := len(mat), len(mat[0])
	length := row * column
	if length != r*c {
		return mat
	}
	res := make([][]int, r)
	for i := 0; i < r; i++ {
		res[i] = make([]int, c)
	}
	for i := 0; i < length; i++ {
		res[i/c][i%c] = mat[i/column][i%column]
	}
	return res
}

//sb题目