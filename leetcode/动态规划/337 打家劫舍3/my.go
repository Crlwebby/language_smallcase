/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
//var f map[*TreeNode]int
//var g map[*TreeNode]int
func rob(root *TreeNode) int {
	f := make(map[*TreeNode]int)
	g := make(map[*TreeNode]int)
	dfs(root, f, g)
	return max(f[root], g[root])
}

func dfs(root *TreeNode, f map[*TreeNode]int, g map[*TreeNode]int) {
	if root == nil {
		return
	}
	dfs(root.Left, f, g)
	dfs(root.Right, f, g)
	f[root] = 0
	f[root] = root.Val + g[root.Left] + g[root.Right]
	g[root] = 0
	g[root] = max(f[root.Left], g[root.Left]) + max(f[root.Right], g[root.Right])
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//Go全局变量怎么定义我还真不知道……var是全局声明，并没有分配空间，用make才能分配空间
//在全局声明以后，然后在main函数体里用make生成一个地址然后赋值过去？确实可行
//回到昨天，昨天笔试的那个.c文件是行不通的。不是说没有实现好队列，而是说队列的做法本身就是行不通的。因为不是层次遍历然后按层加在一起这样做的
//那个思路是错的。我看看能不能改进一下当前的做法，如何在没有字典的情况下，因为只用了四个变量,f(root.left),f(root.right),g(root.left),g(root.right)
//那么应该是可以的，定义四个显式的int，大概可以保存DP结果吧？