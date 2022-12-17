/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head == NULL)
        return NULL;
    if(head->val == val)
        return head->next;
    struct ListNode* temp = head;
    while(temp->next){
        if(temp->next->val == val){
            if(temp->next->next == NULL)
                temp->next = NULL;
            else
                temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
    return head;
}