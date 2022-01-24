import "fmt"

func maxPoints(points [][]int) int {
	n := len(points)
	if n <= 2 {
		return n
	}
	ans := 0
	for i := 0; i < n; i++ {
		//fmt.Printf("(%d,%d)\n",points[i][0],points[i][1])
		slope := make(map[[2]int]int)
		for j := i + 1; j < n; j++ {
			num := [2]int{0, 0}
			deltaY := points[j][1] - points[i][1]
			deltaX := points[j][0] - points[i][0]
			if deltaX == 0 {
				num[0] = points[j][0]
			} else if deltaY == 0 {
				num[1] = points[j][1]
			} else {
				fix := gcd(deltaX, deltaY)
				num[0] = deltaX / fix
				num[1] = deltaY / fix
			}
			slope[num]++
		}
		//fmt.Println(slope)
		for _, v := range slope {
			if v+1 > ans {
				ans = v + 1
			}
		}
	}
	return ans
}

//会做了还是蛮有意思的，官方题解给的思路真清楚
//判断直线，就是判断斜率，于是直接暴力……两两判断斜率，并将斜率计入哈希，统计个数。
//几个易错点
//1.最后的统计个数要加1，因为斜率相同时只加一，但是点其实有两个； 30行
//2.注意处理x相同或y相同的点，这种斜率比较特殊，不能直接用通用算法做，会除零
//3.斜率是浮点数，考虑到可能的误差，用二元组保存斜率最好（官方题解这个考虑还是很周到滴！）
//其他的嘛……官方的题解考虑的很周到，但是很多地方我并没有看目标周到在哪里，让人一头雾水看不懂，于是就有这个简单一些的版本
//不喜欢ACM的形式，考虑到每个角落是很蠢很麻烦的事情。有bug了看日志，再修就是了
func gcd(a int, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
