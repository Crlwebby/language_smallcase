/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
	var slow, fast *ListNode = head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	return slow
}

//除了for循环里这个条件表达式给我搞懵了以外，其它都还好，感觉快慢指针找中间节点应该做过类似的题目……