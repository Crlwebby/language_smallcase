/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
	fast, slow := head, head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			ans := head
			for ans != slow {
				ans = ans.Next
				slow = slow.Next
			}
			return ans
		}
	}
	return nil
}

//想不到时至今日，过了好几个月了，还是在这做链表题，真是惭愧啊
//而且代码还是抄的之前的代码……
//我想的条件，fast != slow，有那么点蠢说实话。因为刚开始fast和slow就是同一个位置，不好搞呀。还得预先处理些边界，想想就头大……还是这样比较好