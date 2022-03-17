func exist(board [][]byte, word string) bool {
	n := len(word)
	row := len(board)
	column := len(board[0])
	result := make([]int, 2*n)
	for i := 0; i < 2*n; i++ {
		//哎，用一维数组保存还是麻烦，空间省了吗？好像省了点，但是时间复杂度大大增加，从O(1)变成O(n)了
		//然后还要考虑不要保存特殊点，就是初始化为-1，然后查找失败，回溯的时候也要恢复为-1
		result[i] = -1
	}
	//result存遍历过的点，以(x,y)的形式存取
	op := [][]int{{0, -1}, {-1, 0}, {1, 0}, {0, 1}}
	var check func(i, j, k int) bool
	check = func(i, j, k int) bool {
		if board[i][j] != word[k] {
			return false
		}
		result[2*k], result[2*k+1] = i, j
		if k == n-1 {
			return true
		}
		for _, direc := range op {
			temp_x := i + direc[0]
			temp_y := j + direc[1]
			if temp_x >= 0 && temp_x < row && temp_y >= 0 && temp_y < column && !in(temp_x, temp_y, result) {
				if check(temp_x, temp_y, k+1) {
					return true
				}
			}
		}
		result[2*k], result[2*k+1] = -1, -1
		return false
	}

	for row_num := 0; row_num < row; row_num++ {
		for col_num := 0; col_num < column; col_num++ {
			if board[row_num][col_num] == word[0] && check(row_num, col_num, 0) {
				return true
			}
		}
	}
	return false
}

func in(x int, y int, s []int) bool {
	//s相当于visited数组，存的是(x,y)的下标，因而每次步长+2;
	for i := 0; i < len(s); i = i + 2 {
		if s[i] == x && s[i+1] == y {
			return true
		}
	}
	return false
}
