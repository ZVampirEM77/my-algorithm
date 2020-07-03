#include <iostream>
#include <unordered_set>
#include "linked_list_op.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; //        } //
        std::unordered_set<ListNode *> ptr_set;
        ListNode * cur_node = head;

        while (cur_node != nullptr) {
          auto iter = ptr_set.find(cur_node);
          if (iter != ptr_set.end()) {
            return *iter;
          } else {
            ptr_set.insert(cur_node);
          }

          cur_node = cur_node->next;
        }

        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * start_node = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                while (start_node != slow) {
                    start_node = start_node->next;
                    slow = slow->next;
                }

                return start_node;
            }
        }

        return NULL;
    }
};
