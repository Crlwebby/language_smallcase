/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
	if left == right {
		return head
	}
	res := &ListNode{Val: 0, Next: head}
	head = res
	var prev *ListNode = nil
	var after *ListNode = nil
	for i := 0; i < left-1; i++ {
		head = head.Next
	}
	prev = head
	head = head.Next
	for i := 0; i < right-left; i++ {
		after = head.Next
		head.Next = after.Next
		after.Next = prev.Next
		prev.Next = after
	}
	return res.Next
}

//=.=头插法 想着练一下，妹想到一练练了四十分钟，真是个傻逼
//真的，下次别头铁了，求你了。链表题老老实实画图做，别脑子硬想，想不过来的，又不是什么难题，画图三五分钟解决的事情，硬要在这里头铁，有毒……