/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = l1;
    struct ListNode* temp = head;
    int carry = 0;
    while(l1 || l2){//经典处理双链表呗，一个为空的情况特殊处理，要么l1为空要么l2为空，都为空就结束循环，判断额外条件后输出
        if(l1 == NULL){
            while(carry && l2){//l1为空的话，进位不一定为空，所以要继续按位相加
                l2->val = l2->val + carry;
                carry = l2->val / 10;
                l2->val %= 10;
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
            if(carry == 0){//要么进位为0，此时把l2后面的节点连起来就行了
                temp->next = l2;
                l2 = NULL;
            }
            //要么链表用完了但是节点还说不为空，那么就把进位接上，新建一个节点
            break;
        }
        if(l2 == NULL){//l2同理
            while(carry && l1){
                l1->val = l1->val + carry;
                carry = l1->val / 10;
                l1->val %= 10;
                temp = temp->next;
                l1 = l1->next;
            }
            if(carry == 0){
                temp->next = l1;
                l1 = NULL;
            }
            break;
        }
        l1->val = l2->val + l1->val + carry;
        carry = l1->val / 10;
        l1->val %= 10;
        temp->next = l1;
        l1 = l1->next;
        l2 = l2->next;
        temp = temp->next;
    }
    if(carry != 0){//补充进位
        struct ListNode* t = malloc(sizeof(struct ListNode));
        t->val = carry;
        t->next = NULL;
        temp->next = t;
        carry = 0;
    }
    return head->next;
}

//许久不见，代码风格似乎有了一些变化？简洁了不少的样子……
//写注释写注释~反正第一版的代码我觉得我已经有点看不懂了，好复杂的样子