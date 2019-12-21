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
        ListNode *phead = NULL;
        if (l1 != NULL && l2 != NULL) {
            ListNode *pCurrent = new ListNode(0);
            phead = pCurrent;
            int res, l1_val, l2_val = 0;
            int carry = 0;
            do {
                l1_val = (l1 != NULL) ? l1->val : 0;
                l2_val = (l2 != NULL) ? l2->val : 0;
                
                res = l1_val + l2_val + carry;
                carry = 0;
                
                if (res >= 10) {
                    carry = 1;
                    pCurrent->val = res - 10;
                } else {
                    pCurrent->val = res;
                }
                
                res = 0;
                
                if ((l1 == NULL || l1->next == NULL) && (l2 == NULL || l2->next == NULL) && carry == 0) {
                    break;
                }
                
                pCurrent->next = new ListNode(0);
                pCurrent = pCurrent->next;
                l1 = (l1 == NULL) ? NULL : l1->next;
                l2 = (l2 == NULL) ? NULL : l2->next;
                
            } while (true);
            
        } else if (l1 == NULL) {
            phead = l2;
        } else if (l2 == NULL) {
            phead = l1;
        }
        
        return phead;
    }
};
