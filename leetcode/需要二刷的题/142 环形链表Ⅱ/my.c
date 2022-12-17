/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){   //数学推导的结果，当快慢指针相遇时，慢指针走向环入口的距离等于链表头到环入口的距离
            struct ListNode *ptr = head;
            while(ptr != slow){
                slow = slow->next;
                ptr = ptr->next;
            }
            return ptr;
        }
    }
    return NULL;
}

//看题解做题还是蛮快乐的……就是不知道能记住多少了
//这题挺高级的，是一道数学题，虽然数学知识要求不高，但是比较难想到，自己太久没学数学，同余方程也看不懂了，落泪
//简单来说，就是通过预定义几个变量，然后会发现变量之间的联系，通过联系解题……好官话，啥也没说啊