/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *left=l1;
    struct ListNode *right=l2;
    struct ListNode *result=l1;
    int i=0,j=0,temp=0;
    while(left!=NULL){
        i++;
        left = left->next;
    }
    while(right!=NULL){
        j++;
        right = right->next;
    }
    if(i == j){
        left = l1;
        while(1){
            left->val = left->val + l2->val + temp;
            temp = 0;
            if(left->val >= 10){
                left->val -=10;
                temp++;
            }
            if(left->next != NULL){
                left = left->next;
                l2 = l2->next;
            }
            else{
                break;
            }
        }
    }
    else{
        int max = 0,min = 0;
        if(i > j){
            max = i;
            min = j;
            left = l1;
            right = l2;
        }
        else{
            max = j;
            min = i;
            left = l2;
            right = l1;
        }
        result = left;
        for(int k = 0; k < min; k++){
            left->val = left->val + right->val + temp;
            temp = 0;
            if(left->val >= 10){
                left->val -= 10;
                temp++;
            }
            left = left->next;
            right = right->next;
        }
        while(1){
            if(temp == 0)
                break;
            left->val += temp;
            temp = 0;
            if(left->val >= 10){
                left->val -= 10;
                temp++;
            }
            if(left->next != NULL)
                left = left->next;
            else
                break;
        }
    }
    if(temp != 0){
            struct ListNode *node = malloc(sizeof(struct ListNode));
            left->next = node;
            node->val = temp;
            node->next = NULL;
        }
    return result;

}