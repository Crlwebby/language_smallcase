/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findSecondMinimumValue(root *TreeNode) int {
	min := root.Val
	ans := -1
	var dfs func(*TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil || ans != -1 && node.Val >= ans {
			return
		}
		if node.Val > min {
			ans = node.Val
		}
		dfs(node.Left)
		dfs(node.Right)
	}
	dfs(root)
	return ans
}

//这是真的一点不会go啊……函数还能像13行这么定义吗？
//当然，也是真的一点不会DFS……DFS搜索的思想还没有深入我心，这还有空摸鱼？还不多多敲代码！