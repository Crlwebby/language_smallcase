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
	var queue []*Node
	queue = append(queue, root, nil)
	temp := root
	for len(queue) != 0 {
		temp = queue[0]
		if temp.Left != nil {
			queue = append(queue, temp.Left)
		}
		if temp.Right != nil {
			queue = append(queue, temp.Right)
		}
		queue = queue[1:]
		if len(queue) == 0 || len(queue) == 1 && queue[0] == nil {
			break
		}
		if queue[0] == nil {
			queue = queue[1:]
			queue = append(queue, nil)
		} else {
			temp.Next = queue[0]

		}
	}
	return root
}

//做法很古怪……但是可以看得出来是层次遍历的思想……
//就是没怎么写过层次遍历和广度优先，不知道怎么去记录那个一层的关系。就是怎么判断某个节点到了下一层这件事情。
//将就着用……看看题解