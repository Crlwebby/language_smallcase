/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge2Lists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = (struct ListNode* )malloc(sizeof(struct ListNode));
    struct ListNode* result = head;
    head->val = 0,head->next=NULL;
    while(l1!= NULL || l2!= NULL){
        if(l1 == NULL){
            head->next = l2;
            break;
        }
        if(l2 == NULL){
            head->next = l1;
            break;
        }
        if(l1->val < l2->val){
            head->next = l1;
            head = head->next;
            l1 = l1->next;
        }
        else{
            head->next = l2;
            head = head->next;
            l2 = l2->next;
        }
    }
    return result->next;
}
struct ListNode* mymergeKLists(struct ListNode **lists, int start, int end){
    if(start > end)
        return NULL;
    else if(end == start)
        return lists[start];
    else if(end == (start + 1))
        return merge2Lists(lists[start],lists[end]);
    else{
        int mid = (start + end)/2;
        struct ListNode* left = mymergeKLists(lists,start, mid);
        struct ListNode* right = mymergeKLists(lists,mid+1,end);
        return merge2Lists(left,right);
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    return mymergeKLists(lists,0,listsSize-1);
}
//这是真的飘了呀哈哈哈哈哈哈
//妹想到呀，现在链表合并做的是真爽…………自从知道预设定一个头结点效果拔群后，妈妈再也不用怕我不会合并链表了！谢谢，有被爽到