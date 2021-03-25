/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    if(head == NULL)
        return 0;
    int result = 0;
    while(head){
        result = 2*result + head->val;
        head = head->next;
    }
    return result;
}