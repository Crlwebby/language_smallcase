/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head,*slow = head;
    while(fast != NULL &&fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

//严格来说这并不是我的思路……是先看了链表判环以后再根据这个思路敲的代码233333
//快慢指针真秒啊！有环就类似于一个操场，跑的快的早晚会套圈跑的慢的，而且环肯定没法结束，如果遇到NULL说明肯定没有环  