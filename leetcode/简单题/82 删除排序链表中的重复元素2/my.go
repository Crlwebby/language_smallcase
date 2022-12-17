/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	prev := &ListNode{-1, head}
	res := prev
	flag := 0
	for head != nil && head.Next != nil {
		if head.Val == head.Next.Val {
			head.Next = head.Next.Next
			flag = 1
		} else {
			if flag == 1 {
				prev.Next = head.Next
				flag = 0
			} else {
				prev = head
			}
			head = head.Next
		}
	}
	if flag == 1 {
		prev.Next = head.Next
	}
	return res.Next
}

//九个月前做过的题目=。= 时间过得这么快的吗？这就又九个月荒废掉了！自己无论是基础知识还是身体素质还是项目能力，都和九个月前没什么差别啊……