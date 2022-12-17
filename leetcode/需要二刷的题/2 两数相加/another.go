/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	ans := &ListNode{-1, l1}
	index := ans
	carry := 0
	for l2 != nil {
		//因为我是把l2加到l1上面的，如果l2为空，继续就好；
		if l1 == nil {
			//如果l1为空，把l2续上就行；
			index.Next = l2
			break
		}
		//这个index什么时候往后遍历很细节，因为上一次循环可能导致l1为空（l1就是index，指针指向的同一个），所以要先判断，再往后循环；
		index = index.Next
		index.Val += carry + l2.Val
		carry = index.Val / 10
		index.Val = index.Val % 10
		l1 = l1.Next
		l2 = l2.Next
	}
	for carry != 0 {
		if index.Next == nil {
			index.Next = &ListNode{carry, nil}
			carry = 0
			break
		}
		//这个和上面一样，先判断是否为空，再进行处理
		index = index.Next
		index.Val += carry
		carry = index.Val / 10
		index.Val = index.Val % 10
	}
	return ans.Next
}

//细节是魔鬼啊，处理细节过于头疼
//简单说来，两个链表的长度有三种可能，进不进位有两种可能，组合起来就是六种可能，都要处理；
