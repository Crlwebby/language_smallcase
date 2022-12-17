type MyLinkedList struct {
	val  int
	next *MyLinkedList
}

func Constructor() MyLinkedList {
	return MyLinkedList{-1, nil}
}

func (this *MyLinkedList) Get(index int) int {
	i := 0
	this = this.next
	for this != nil {
		if i == index {
			return this.val
		}
		this = this.next
		i++
	}
	return -1
}

func (this *MyLinkedList) AddAtHead(val int) {
	temp := &MyLinkedList{val, nil}
	temp.next = this.next
	this.next = temp
}

func (this *MyLinkedList) AddAtTail(val int) {
	prev := this
	this = this.next
	for this != nil {
		prev = this
		this = this.next
	}
	prev.next = &MyLinkedList{val, nil}
}

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	prev := this
	if index <= 0 {
		this.AddAtHead(val)
		return
	}
	this = this.next
	for index != 0 && this != nil {
		prev = this
		this = this.next
		index--
	}
	if index != 0 {
		return
	}
	temp := &MyLinkedList{val, nil}
	temp.next = prev.next
	prev.next = temp
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	prev := this
	if index < 0 {
		return
	}
	this = this.next
	for index != 0 && this != nil {
		prev = this
		this = this.next
		index--
	}
	if prev.next != nil {
		prev.next = prev.next.next
	}
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
//就很烦力扣出这种纯纯的设计题，设计链表也是，设计哈希也是，感觉很麻烦也很无聊。
//如果要造个轮子，我为什么要在力扣上写这种东西呢？我来这就是练习算法的，练习一下各种数据结构的使用。然后你给我个让我实现数据结构？
//完全没必要啊，练习不够吗……