/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    struct ListNode *temp = head;
    int length = 0;
    while(temp){
        length++;
        temp = temp->next;
    }
    *returnSize = length;
    int *result = malloc(sizeof(int) * length);
    for(int i = 0; i < length; i++){
        result[length- i - 1] = head->val;
        head = head->next;
    }
    return result;
}
//第一道做出来的链表题……链表反转链表合并都不会了，麻烦大了。。。