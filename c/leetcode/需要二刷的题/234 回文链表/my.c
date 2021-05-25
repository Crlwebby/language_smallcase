/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    struct ListNode* temp=head;
    int len=0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    int a[len];
    for(int i = 0; i < len; i++)
        a[i] = 0;
    temp = head;
    int i = 0;
    while(temp != NULL){
        a[i++]=temp->val;
        temp = temp->next;
    }
    i = len -1;
    while(head != NULL){
        if(head->val != a[i])
            return false;
        head = head->next;
        i--;
    }
    return true;
}
//最笨比的做法……因为这个链表它只有数字，所以干脆把数字全取到数组里，然后从尾到头匹配下
//题目的O(n)时间和O(1)空间感觉好难呐，过分了！想不出来呀！
//自己真的是……字符串菜狗一条