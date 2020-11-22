#include <iostream>
#include "linked_list_op.h"

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode * cur_node = head;
        ListNode ** pointer_to_node_pointer = &head;

        while(cur_node != nullptr && cur_node->next != nullptr) {
            ListNode * adjacent_node = cur_node->next;
            cur_node->next = adjacent_node->next;
            adjacent_node->next = cur_node;
            *pointer_to_node_pointer = adjacent_node;

            pointer_to_node_pointer = &(cur_node->next);
            cur_node = cur_node->next;
        }

        return head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode * cur_node = head;
        ListNode * pre_node = new ListNode();
        ListNode * new_head = cur_node->next;

        while(cur_node != nullptr && cur_node->next != nullptr) {
            ListNode * adjacent_node = cur_node->next;
            cur_node->next = adjacent_node->next;
            adjacent_node->next = cur_node;
            pre_node->next = adjacent_node;

            pre_node = cur_node;
            cur_node = cur_node->next;
        }

        return new_head;
    }

    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *nn_node = swapPairs(head->next->next);
        ListNode *res = head->next;
        head->next->next = head;
        head->next = nn_node;
        return res;
    }
};