struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-by-leetcode-solution-jvs5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//递归的思路确实是想到过的，但是递归水平太差，没能写出来
//至今其实也不是很理解，为什么能最后返回尾结点
//原来如此……其实和想象中的类似，就是用一个类似全局变量的东西保存最后的尾结点，也就是反转后的头节点，只不过在递归的方法中，不需要全局定义，
//第一次进入递归定义的newHead，然后返回也是用newHead，就够了
//遇见NULL或者head->next == NULL，意识到是尾结点后返回这个节点，然后一直返回这个节点直到递归入口，就实现了需求