/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL)
        return NULL;
    struct ListNode* current = head;
    struct ListNode* pnext = head->next;
    head->next = NULL;
    while(pnext){
        head = pnext;
        pnext = head->next;
        head->next = current;
        current = head;
    }
    return head;
}
//亏我在阿里面试的时候还说一个临时变量就可以实现链表反转……到头来还是用了两个变量，而且逻辑还很复杂……赶紧去看看大佬怎么写的吧，别折磨自己了……