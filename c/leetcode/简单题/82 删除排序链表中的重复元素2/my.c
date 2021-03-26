/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode* inode = malloc(sizeof(struct ListNode));
    inode->val = -1;
    inode->next = head;
    struct ListNode* index = inode;
    while(index->next && index->next->next){//进行外层遍历，前面这个条件是为了保护后者不取到空值；
    //为什么index不可能为空呢？嗯…………
    //首先，index是额外的头结点，所以最初的循环不可能为空；其次，在有重复值、删除节点的时候，都是以后一位进行判断删除的，
    //不会删除本身的节点，而且删除完毕后都有continue，于是保留了被删除节点前的一个节点，就不会被置空了
        if(index->next->val == index->next->next->val){
            int t = index->next->val;
            //t用来记录需要被删除的值
            while(index->next && index->next->val == t){
                    index->next = index->next->next;
            }
        }
        else
            index = index->next;
    }
    return inode->next;
}
//这题给我写麻了……看看这满屏的next和next->next，就知道有多丧心病狂了……
//得亏前两天刚看见过用头结点解链表题的技巧，不然的话第一个节点的处理人要死了，赶紧加几个注释，不然没几天就看不懂了
//效率分析的话，好像到不了n^2？中间那个while虽然又经历一次遍历，但是只遍历到t，而且只在有重复数据的情况下才会遍历
//也就是说，什么情况会到n^2呢？那也就所有数字全部都是1……不对啊，那也就o(n)，因为外层遍历只有一次，第二次就为空了

//我是笨比……