/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connect(root *Node) *Node {
	if root == nil {
		return nil
	}
	queue := []*Node{root}
	for len(queue) != 0 {
		length := len(queue)
		temp := queue[0]
		for i := 0; i < length; i++ {
			if i+1 < length {
				temp.Next = queue[i+1]
			}
			if temp.Left != nil {
				queue = append(queue, temp.Left)
			}
			if temp.Right != nil {
				queue = append(queue, temp.Right)
			}
			temp = temp.Next
		}
		queue = queue[length:]
	}
	return root
}

//稍微干净了一点，层次遍历用每一层的长度进行计数，不用nil标记