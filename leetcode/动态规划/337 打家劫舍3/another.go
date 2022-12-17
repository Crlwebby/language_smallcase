/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rob(root *TreeNode) int {
	s, ds := dfs(root)
	//select, don't select
	return max(s, ds)
}

func dfs(root *TreeNode) (int, int) {
	if root == nil {
		return 0, 0
	}
	s_left, d_left := dfs(root.Left)
	//select left, don't select left
	s_right, d_right := dfs(root.Right)
	//select right, don't select right
	s := root.Val + d_left + d_right
	ds := max(s_left, d_left) + max(s_right, d_right)

	return s, ds
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//清爽了不少，除了变量命名有点头疼……