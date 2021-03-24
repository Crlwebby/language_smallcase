/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL || l2 == NULL)
        if(l1 == NULL){
            return l2;
        }
        else{
            return l1;
        }
    struct ListNode* main;
    struct ListNode* another;
    struct ListNode* result;
    struct ListNode* prev;
    if(l1->val <= l2->val){
        result = l1;
        prev = l1;
        main = l1->next;
        another = l2;
    }
    else{
        result = l2;
        prev = l2;
        main = l2->next;
        another = l1;
    }
    while(main || another){
        if(main == NULL){
            prev->next = another;
            break;
        }
        else if(!another){
            break;
        }
        else{
            if(main->val < another->val){
                prev = main;
                main = main->next;
            }
            else{
                struct ListNode* temp = another;
                another = another->next;
                prev->next = temp;
                temp->next = main;
                prev = prev->next;
            }
        }
    }
    return result;
}
//挺长了，五十多行的代码，写的还是比较冗长的，强行不额外建立链表，在原链表的基础上加加减减，确实挺麻烦的
//思路无非就是标记返回的链表头，然后一个main一个another指针标记两条链表，逐个比较然后加入到main中
//欸？这样一描述，怎么赶紧好像git的merge操作一样……

//………………我是蠢驴，我单想着不额外创建一条链表，没想到通过引入头节点就可以做到这样子的事情，不需要再插入节点，只需弄一个头节点，改写下next就行了，裂开……