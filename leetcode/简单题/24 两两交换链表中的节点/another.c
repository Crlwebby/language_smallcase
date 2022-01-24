struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next == NULL)
            return head;
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->next = head;
    struct ListNode* temp = node;
    while(node->next && node->next->next){
        struct ListNode* swap = node->next;
        node->next = node->next->next;
        swap->next = swap->next->next;
        node->next->next = swap;
        node = node->next->next;
    }
    return temp->next;
}

//差点绕晕了……链表题一定要自己多画图画图！否则就会和我一样有丢失节点的现象发生，画个图什么都清楚了