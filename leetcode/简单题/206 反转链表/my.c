struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *before = NULL;
    struct ListNode *after = head;
    if(head == NULL)
        return head;
    while(head->next){
        after = head->next;
        head->next = before;
        before = head;
        head = after;
    }
    head->next = before;
    return head;
}

//有更简单的写法，head->next用head代替

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *before = NULL;
    struct ListNode *after = head;
    while(head){
        after = head->next;
        head->next = before;
        before = head;
        head = after;
    }
    return before;
}