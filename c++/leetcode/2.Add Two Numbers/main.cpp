/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3;
        l3=new ListNode(0);
        ListNode *l4=l3;                    //l3移动,l4记录头结点返回；
        int sum=0;
        while(l1!=NULL||l2!=NULL)
        {
            if(l1==NULL)
            {
                l3->next=l2;
                break;
            }
            else if(l2==NULL)
            {
                l3->next=l1;
                break;
            }
            else{
                l3->next = new ListNode(0);
                l3=l3->next;
                l3->val=(l1->val+l2->val+sum)%10;
                sum=(l1->val+l2->val+sum)/10;
                l1=l1->next;
                l2=l2->next;
            }
        }
        while(sum!=0){
        //处理进位
            if(l3->next==NULL)
            //仅有进位
            {
                l3->next = new ListNode(0);
                l3->next->val=sum;
                sum=0;
                continue;
            }
            l3=l3->next;
            (l3->val)+=sum;
            sum=(l3->val)/10;
            l3->val=(l3->val)%10;
        }
        return l4->next;
    }
};

//leetcode大神作品
/*Step 1: Do l1=l1+l2 ignoring carry.
Step 2: Do the carry to correct l1.
Here is my submission: */

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode *head1;
		head1 = l1;
		//l1=l1+l2
		do
		{
			l1->val = l1->val + l2->val;
			if(l1->next==nullptr)
			{
				if (l2->next!=nullptr)
				{
					l1->next = new ListNode(0);
				}
			}
			l1 = l1->next;
		} while ((l2=l2->next)!=nullptr);

		l1 = head1;
		while (l1!=nullptr)
		{
			if (l1->val / 10)
			{
				if (l1->next == nullptr)
				{
					l1->next = new ListNode(0);
				}
				l1->next->val += l1->val / 10;
				l1->val %= 10;
			}
			l1 = l1->next;
		}
		l1 = head1;
		return l1;
	}
};
