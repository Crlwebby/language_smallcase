/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    int t = 0;
    struct ListNode* temp = head;
    while(head && head->next){
        t = head->val;
        head->val = head->next->val;
        head->next->val = t;
        head = head->next->next;
    }
    return temp;
}

//整挺好，先用简单方法做了一下，直接交换值，爽快！
//再用medium方法做吧，就是题目暗示的，别用值交换！交换链表！