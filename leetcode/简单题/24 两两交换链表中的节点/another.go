/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	ans := &ListNode{-1, head}
	res := ans
	for ans.Next != nil && ans.Next.Next != nil {
		right1 := ans.Next
		right2 := right1.Next
		right3 := right2.Next
		ans.Next = right2
		right2.Next = right1
		right1.Next = right3
		ans = ans.Next.Next
	}
	return res.Next
}

//hhhhhh跟上次一样，不多说了，就是画个图什么都清楚了，right1 right2 right3的，就是交换一个链表里的两个元素，要涉及四个节点
//最前面的用ans了，后面三个用right1 right2 right3来表示了，比用next.next之类的要清楚一点
