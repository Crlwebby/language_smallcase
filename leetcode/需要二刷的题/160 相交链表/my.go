/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	flag1, flag2 := 0, 0
	point1, point2 := headA, headB
	for point1 != nil || point2 != nil {
		if point1 == point2 {
			return point1
		}
		if point1 == nil {
			if flag1 == 0 {
				point1 = headB
			} else {
				break
			}
		} else {
			point1 = point1.Next
		}
		if point2 == nil {
			if flag2 == 0 {
				point2 = headA
			} else {
				break
			}
		} else {
			point2 = point2.Next
		}
	}
	return nil
}

//解题思路看懂了，就还行，无非就是，如何交换遍历到另外一个链表，要稍微考虑一下；
//就这里而言，我用了两个flag记录有没有切换这个动作，也暂时想不到更好的办法了……
//噢，少了一个想法，就是两个链表不相交，即使不用flag，也不会死循环的。
//一个链表长为M，一个链表长为N，同时遍历，最后都到M+N，同为nil退出循环；
//所以循环的条件设为 point1 != point2可能会更好一点