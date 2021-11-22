/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "math"

func findTilt(root *TreeNode) int {
	res := 0
	traverse(root, &res)
	return res
}

func traverse(root *TreeNode, res *int) {
	if root == nil {
		return
	}
	left, right := 0, 0
	if root.Left != nil {
		traverse(root.Left, res)
		left = root.Left.Val
	}
	if root.Right != nil {
		traverse(root.Right, res)
		right = root.Right.Val
	}
	*res = *res + int(math.Abs(float64(right-left)))
	root.Val += left + right
}

//思想还好理解的，就是后序遍历一下，然后记录每个节点的坡度值，再把左右节点的值加一下就完事儿了

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

//=.= 自己写个绝对值，不调用库函数，快了4ms……，