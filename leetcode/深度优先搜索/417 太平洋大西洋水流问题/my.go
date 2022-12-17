func pacificAtlantic(heights [][]int) [][]int {
    row := len(heights)
    column := len(heights[0])
    var answer [][]int
    var visited [][]int
    for i := 0; i < row; i++{
        temp := make([]int,column)
        visited = append(visited,temp)
    }
    var dfs func(i,j,key int) {
    //因为要进行四次深搜（上下左右，然后找到上左 和 下右 都有一条能到达的路径，该点符合条件）
    //我用二进制1111进行标记，也就是8、4、2、1的key
    //顺序是上左下右
    //如果符合条件，其实也就是除了0100 1000 1100 0000 0001 0011 0010这七种，均可以到达，所以就是排除0 1 2 3 4 8 12这七种。
        if i < 0 || i == row || j < 0 || j == column || visited[i][j] != 0{
            return
        }
        if i == 0 || j == 0 || i == row - 1 || j == column - 1{
            visited[i][j] += key
        }else
    }
}

//hhhhhhhh，感觉好有意思，我是怎么天马行空的想出这样的解法的……
//总之，十分的不可行，而且巨麻烦=。=，但是就做个记录
//看了别人的解法后感觉豁然开朗了，多做几次深搜其实就OK的