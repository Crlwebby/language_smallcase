//原来如此！我悟了！原本就想过O(1)的时间肯定是从中间反转，然后头和中间同时开始遍历链表
//当时觉得难点是如何找到中间的节点，a->val == a->next->val肯定不可行，然后就陷入思维僵局了……
//怎么就忘了快慢指针啊……可恶啊

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    struct ListNode *fast=head;
    struct ListNode *before = NULL;
    struct ListNode *after=head;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        after = head->next;
        head->next = before;
        before = head;
        head = after;
    }
    if(fast == head){//fast == head 的情况只会在链表节点小于等于两个的时候才会发生，否则fast每次走两步，head走一步，肯定不会相同
        if(head->next == NULL)//只有一个元素的情况下，肯定是回文的
            return true;
        else if(head->next->val == head->val)//两个元素的情况下，如果相同则是回文的
            return true;
        else
            return false;
    }
    after = head->next;
    head->next = before;
    if(fast->next != NULL){
        fast = after;
    }
    else{
        head = head->next;
        fast = after;
    }
    while(head){
        if(head->val != fast->val)
            return false;
        head = head->next;
        fast = fast->next;
    }
    return true;
}
//写是可以写的没什么问题，就是这写的好像有点累啊……五十行的代码，说明写的绝不轻松，中间从25-41这十六行
//都是基于样例的条件判断，根据样例写代码实锤了，说明写之前并没有怎么规划好