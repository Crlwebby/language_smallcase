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
	cnt := 1
	var res *ListNode = head
	var before *ListNode = nil
	//区间前一个节点
	var after *ListNode = nil
	//区间后一个节点
	var begin *ListNode = nil
	var end *ListNode = nil
	for head != nil {
		if cnt == left-1 {
			before = head
		} else if cnt == left {
			begin = head
		} else if cnt == right {
			end = head
		} else if cnt == right+1 {
			after = head
		}
		head = head.Next
		cnt++
	}
	end.Next = nil
	temp := reverse(begin)
	if before == nil {
		//如果第一个就要反转，那直接把得到的新链表头赋给他，然后把原本的尾巴接上来就行
		res = temp
	} else {
		before.Next = end
	}
	begin.Next = after
	return res
}

func reverse(head *ListNode) *ListNode {
	//中间区间的链表当作一个单独的链表进行反转,返回尾部
	var prev *ListNode = nil
	var after *ListNode = head
	for head != nil {
		after = head.Next
		head.Next = prev
		prev = head
		head = after
	}
	return prev
}

//感觉还是蛮难的，我还算是取巧了，做了一遍链表翻转的题再来做这个
//基本上就是把区间视为一个完整的链表，把这个链表掐尾，然后就是普通的链表翻转题
//其它就是边界条件再处理一下就OK，就是怎么把这条翻转的链表接回去，稍微处理一下就行了
//就是练习一下链表怎么写，还可以吧……