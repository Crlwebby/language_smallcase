type Point struct {
	X   int
	Y   int
	Val int
}

func findPeakGrid(mat [][]int) []int {
	m := len(mat)
	n := len(mat[0])
	if m == n && m == 1 {
		return []int{0, 0}
	}
	midi, midj := m/2, n/2
	for {
		//fmt.Println(midi,midj)
		temp := Point{midi, midj, mat[midi][midj]}
		points := make([]Point, 4) //0,1,2,3 right,left,top,down
		points[0], points[1], points[2], points[3] = Point{midi - 1, midj, -1}, Point{midi + 1, midj, -1}, Point{midi, midj - 1, -1}, Point{midi, midj + 1, -1}
		if midi >= 1 {
			points[0].Val = mat[midi-1][midj]
		}
		if midi < m-1 {
			points[1].Val = mat[midi+1][midj]
		}
		if midj >= 1 {
			points[2].Val = mat[midi][midj-1]
		}
		if midj < n-1 {
			points[3].Val = mat[midi][midj+1]
		}
		if temp.Val > points[0].Val && temp.Val > points[1].Val && temp.Val > points[2].Val && temp.Val > points[3].Val {
			break
		} else {
			temp := &temp
			for _, v := range points {
				temp = max(temp, &v)
			}
			midi, midj = temp.X, temp.Y
		}
	}

	return []int{midi, midj}
}

func max(a *Point, b *Point) *Point {
	if a.Val > b.Val {
		return &Point{a.X, a.Y, a.Val}
	}
	return &Point{b.X, b.Y, b.Val}
}

//很魔幻的一道题……主要是矩阵到底怎么二分嘛，上下左右四个方向呢……
//我就参考162寻找峰值的思想，直接从矩阵中点开始找，然后一直往更大的方向找，肯定能找得到的。
//噢，写出来就明白了，往更大的方向找以后，保证那个区间内必定会有顶峰；然后在有顶峰的区间不断重复前面的过程，就可以缩小范围找到点了
//=。=真的懒得写了，NND，二维不好搞二分，因为都是几何图形的中点，不好处理。而且边界问题很麻烦，就这样吧^^