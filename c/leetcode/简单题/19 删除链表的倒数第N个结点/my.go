/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	count := 0
	for temp := head; temp != nil; temp = temp.Next {
		count++
	}
	dummy := &ListNode{0, head}
	prev := dummy
	for count != n {
		prev = head
		head = head.Next
		count--
	}
	prev.Next = head.Next
	return dummy.Next
}

//两遍扫描的屑……想想扫一遍怎么实现，然后再学习一下题解
//算了不学了，看了题解双指针，第一个从k开始，第二个从零开始，本质上也还是两次遍历，小技巧，不想写了