/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	var before *ListNode = nil
	var after *ListNode = head
	for head != nil {
		after = head.Next
		head.Next = before
		before = head
		head = after
	}
	return before
}

//抄自己作业……反转链表也不会写了，可恶