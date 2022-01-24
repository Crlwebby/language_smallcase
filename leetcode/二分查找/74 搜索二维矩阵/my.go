func searchMatrix(matrix [][]int, target int) bool {
	row := len(matrix) - 1
	column := len(matrix[0]) - 1
	i, j := 0, 0
	for i <= row {
		mid := (row + i) / 2
		/*if matrix[mid][0] == target {
			row = mid
			break
		} else if matrix[mid][0] > target {
			row = mid - 1
		} else {
			i = mid + 1
		}*/
		if matrix[mid][0] > target {
			row = mid - 1
		} else {
			i = mid + 1
		} //没有本质区别，还是不太能理解模糊的二分查找，就这样吧先……
	}
	if row < 0 {
		return false
	}
	for j <= column {
		mid := (j + column) / 2
		if matrix[row][mid] == target {
			return true
		} else if matrix[row][mid] > target {
			column = mid - 1
		} else {
			j = mid + 1
		}
	}
	return false
}

//给写自闭了=。=，wa了八次……
//二分查找，找一个不确定的位置，以前就遇见过但是没有总结，于是今天出大问题了，写的要死要活，妈耶
//总之，按自己的总结是，i,j两个指针，右指针能指向最终所要查找的位置，证明不会……