/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) <= 0 {
		return nil
	}
	ans := &TreeNode{preorder[0], nil, nil}
	boundary := 0
	for i, v := range inorder {
		if v == preorder[0] {
			boundary = i
			break
		}
	}
	ans.Left = buildTree(preorder[1:boundary+1], inorder[0:boundary])
	ans.Right = buildTree(preorder[boundary+1:len(preorder)], inorder[boundary+1:len(inorder)])
	//这里的分界点画图理解吧，把下标写出来就都清楚了。想是很容易想错的。
	return ans
}

//只能说基本还都是上回的思路，但是不一样的是题解，看了题解明白了些。
//前序和中序，分别按照中、左、右和左、中、右的顺序。在前序序列中的第一个取出来，在中序中找到，然后把两个序列都分成左右子树单独处理
//难点就在于怎么分。其实按照左子树长度一致的原则，你找到中序遍历的中点时，左子树和右子树长度也都知道了，按照这个把两个序列分开即可。