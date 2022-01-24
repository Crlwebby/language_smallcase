func traverse(root *TreeNode, res *int) int {
	if root == nil {
		return 0
	}
	left := traverse(root.Left, res)
	right := traverse(root.Right, res)
	*res = *res + abs(right-left)
	root.Val += left + right
	return root.Val
}

//关键函数。这样子简洁了好多，按官方题解的思路，这叫dfs，不过应该差差不多，都类似后续遍历嘛，问题不大~