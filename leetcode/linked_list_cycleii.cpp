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
        if (head == nullptr || head->next) {
            return nullptr;
        }

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
};

int main() {
  ListNode * list_ins = CreateCycledLinkedList<ListNode>(7, 1);
  ListNode * cur = list_ins;

  Solution * solution_ins = new Solution();
  ListNode * cycle_start_node = solution_ins->detectCycle(list_ins);
  std::cout << "cycle start from node " << cycle_start_node->val << std::endl;

  return 0;
}
