/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* temp = head;
    if(temp == NULL || temp->next == NULL)
        return head;
    
    while(temp && temp->next){
        if(temp->val == temp->next->val){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

//人面完字节情绪比较低迷，做道简单题提高一下大脑兴奋度，不应该会困的……
//准备不充分嘛不就是，别急！