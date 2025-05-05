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
            int carry = 0, l1v, l2v;
            ListNode* l1p = l1, *l2p = l2, *cp;
            ListNode* base = new ListNode();
            cp = base;
            bool first_time = true;
            while(carry != 0 || l1p!=nullptr || l2p!=nullptr){
                l1v = (l1p==nullptr) ? 0 : l1p->val;
                l2v = (l2p==nullptr) ? 0 : l2p->val;
                if(first_time){
                    cp->val = (l1v+l2v)%10;
                    first_time = false;
                }else{
                    ListNode *n = new ListNode((l1v+l2v+carry) % 10);
                    cp->next = n;
                    cp = cp->next;
                }
                carry = (l1v+l2v+carry) >= 10 ? 1 : 0;
                l1p = (l1p == nullptr) ? nullptr : l1p->next;
                l2p = (l2p == nullptr) ? nullptr : l2p->next; 
            }
            return base;
        }
    };