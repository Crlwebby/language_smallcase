/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* result = malloc(sizeof(struct ListNode));
    result->val = 0,result->next = NULL;
    struct ListNode* cur=result;
    while(l1 || l2){
        if(l1 == NULL){
            cur->next = l2;
            break;
        }
        if(l2 == NULL){
            cur->next = l1;
            break;
        }
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        else{
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
    }
    return result->next;
}

//这种写法简直不要太爽…………四五分钟就写完了，思路无比清晰，头节点真爽！