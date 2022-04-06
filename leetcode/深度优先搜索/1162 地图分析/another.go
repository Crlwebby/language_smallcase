func maxDistance(grid [][]int) int {
    row := len(grid)
    column := len(grid[0])
    ans := -1
    const INT_MAX = int(^uint(0) >> 1)
    var visited [][]int
    direction := [][]int{{-1,0},{0,-1},{1,0},{0,1}}
    for i := 0; i < row; i++{
        temp := make([]int,column)
        visited = append(visited,temp)
    }
    var point [][]int
    for i := 0; i < row; i++{
        for j := 0; j < column; j++{
            if grid[i][j] == 1{
                point = append(point,[]int{i,j})
            }
        }
    }
    if len(point) == 0 || len(point) == row * column{
        return -1
    }

    for len(point) > 0{
        ans++
        TempQueue := point
        point = nil
        for len(TempQueue) > 0{
            p := TempQueue[0]
            TempQueue = TempQueue[1:]
            for i := 0; i < 4; i++{
                temp_x := p[0] + direction[i][0]
                temp_y := p[1] + direction[i][1]
                if temp_x < 0 || temp_x == row || temp_y < 0 || temp_y == column || visited[temp_x][temp_y] != 0{
                    continue
                }
                visited[temp_x][temp_y] = 2
                point = append(point,[]int{temp_x,temp_y})
            }
        }
    }


    return ans
}

//这个真的挺厉害的，原文链接放在下面了。
//简单来说，就相当于从外往里找吧。先把所有的石头找到，然后根据这些石头找到最近的水域，并加入到队列中，然后把石头清空
//这样就找到了所有距离为1的水域，然后从这些水域出发继续找，找到距离为2的水域
//就这样层层扩散，直到扩散完毕，最后一次就是最远的距离了。NB


作者：ijkbytesss
链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/goduo-yuan-yan-du-you-xian-bian-li-by-ijkbytesss/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。