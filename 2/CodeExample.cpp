/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* root = NULL;
            ListNode* current ;
            int carry = 0;
            int sum=0;
            if(l1!=NULL||l2!=NULL){
                carry=(l1==NULL?0:l1->val)+(l2==NULL?0:l2->val)+carry;
                sum=carry%10;
                carry=carry/10;
                ListNode* tmp =new ListNode(sum);
                root=current= tmp;
                if(l1)l1= l1->next;
                if(l2)l2= l2->next;
            }
            while(l1!=NULL||l2!=NULL){
                carry=(l1==NULL?0:l1->val)+(l2==NULL?0:l2->val)+carry;
                sum=carry%10;
                carry=carry/10;
                ListNode* tmp =new ListNode(sum);
                current->next= tmp;
                current =tmp;
                if(l1)l1= l1->next;
                if(l2)l2= l2->next;
            }
            if(carry!=0) current->next= new ListNode(carry);
            return root;
        }
};