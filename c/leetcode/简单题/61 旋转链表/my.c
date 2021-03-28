struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL || head->next == NULL)//处理简单情况，0个或一个直接返回即可
        return head;
    struct ListNode* temp = head;
    int length = 1;
    while(head->next){//计算链表长度
        length++;
        head = head->next;
    }
    if(k >= length)
        k = k%length;
    head->next = temp;//把链表变成环
    head = head->next;
    int i = 1;
    while(i < length - k){//从链表头开始，遍历一定次数就到了新的链表尾
        head = head->next;
        i++;
    }
    temp = head->next;//获取链表头，同时断开节点
    head->next = NULL;
    return temp;
}


