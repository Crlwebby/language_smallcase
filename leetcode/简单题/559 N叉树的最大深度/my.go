/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
	return traverse(root)
}

func traverse(root *Node) int {
	if root == nil {
		return 0
	}
	res := 0
	for _, v := range root.Children {
		temp := traverse(v)
		res = max(res, temp)
	}
	return res + 1
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

//平衡二叉树都做过了，判断一棵树的深度还不简单？即使这是N叉树……