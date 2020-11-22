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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            return head;
        }
        
        ListNode * cur_node = head;
        ListNode * pre_node = nullptr;
        ListNode * next_node = nullptr;

        while(cur_node != nullptr) {
            next_node = cur_node->next;
            cur_node->next = pre_node;
            pre_node = cur_node;
            cur_node = next_node;
        }
        
        return pre_node;
    }

    ListNode* reverseList2(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *res = reverseList2(head->next);
        head->next->next = head;
        head->next = nullptr;

        return res;
    }
};