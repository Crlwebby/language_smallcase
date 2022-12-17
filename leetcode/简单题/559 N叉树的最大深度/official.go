/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func maxDepth(root *Node) int {
	if root == nil {
		return 0
	}
	depth := 0
	for _, v := range root.Children {
		if childdepth := maxDepth(v); childdepth > depth {
			depth = childdepth
		}
	}
	return depth + 1
}

//官方的题解还是简洁，要利用上Go的语言性质啊。