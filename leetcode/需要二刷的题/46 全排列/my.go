func permute(nums []int) [][]int {
	var res [][]int
	len := len(nums)
	temp := make([]int, len)    //存储已经排列好的数字
	visited := make([]int, len) //一个标记数组，记录哪些数字已经用过了
	dfs(nums, 0, temp, visited, len, &res)
	return res

}

func dfs(nums []int, pos int, temp []int, visited []int, len int, res *[][]int) {
	if pos == len {
		mid := make([]int, len)
		copy(mid, temp)
		*res = append(*res, mid)
		return
	}
	for i := 0; i < len; i++ {
		if visited[i] == 0 {
			temp[pos] = nums[i]
			visited[i] = 1
			dfs(nums, pos+1, temp, visited, len, res)
			visited[i] = 0
		}
	}
}

//原本只是看啊哈C看到一个全排列，觉得蛮有趣的，思路也简单，就想写一下
//妹想到掉进了golang的语言陷阱=。=，给我整傻了
//倒也不是说语言陷阱。就单纯的，用的不熟吧。然后各种踩坑爆雷，你看这dfs函数满满的参数就知道有多难顶了……