#include <iostream>
#include <queue>
#include <vector>

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res_vec;
    if (root == nullptr) {
        return res_vec;
    }

    std::stack<TreeNode *> node_stack;
    node_stack.push(root);
    std::queue<TreeNode *> processing_queue;
    int node_level = 0;

    while(!node_stack.empty()) {
        std::vector<int> level_vec;
        uint32_t ele_count = node_stack.size();
        for (int i = 0; i < ele_count; i++) {
            processing_queue.push(node_stack.top());
            node_stack.pop();
        }
        for (int i = 0; i < ele_count; i++) {
            TreeNode *cur_node = processing_queue.top();
            processing_queue.pop();
            level_vec.push_back(cur_node->val);
            if (node_level % 2) {
                if (cur_node->right) {
                    node_stack.push(cur_node->right);
                }
                if (cur_node->left) {
                    node_stack.push(cur_node->left);
                }
            } else {
                if (cur_node->left) {
                    node_stack.push(cur_node->left);
                }
                if (cur_node->right) {
                    node_stack.push(cur_node->right);
                }
            }
        }

        node_level++;
        res_vec.push_back(level_vec);
    }

    return res_vec;
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res_vec;
    if (root == nullptr) {
        return res_vec;
    }

    std::stack<TreeNode *> node_stack[2];
    int node_level = 0;
    node_stack[(node_level % 2)].push(root);

    while((!node_stack[0].empty()) || (!node_stack[1].empty())) {
        int stack_num = node_level % 2;
        std::vector<int> level_vec;
        while(node_stack[stack_num].size()) {
            TreeNode *cur_node = node_stack[stack_num].top();
            node_stack[stack_num].pop();
            level_vec.push_back(cur_node->val);
            if (stack_num) {
                if (cur_node->right) {
                    node_stack[1 - stack_num].push(cur_node->right);
                }
                if (cur_node->left) {
                    node_stack[1 - stack_num].push(cur_node->left);
                }
            } else {
                if (cur_node->left) {
                    node_stack[1 - stack_num].push(cur_node->left);
                }
                if (cur_node->right) {
                    node_stack[1 - stack_num].push(cur_node->right);
                }
            }
        }

        node_level++;
        res_vec.push_back(level_vec);
    }

    return res_vec;
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res_vec;
    if (root == nullptr) {
        return res_vec;
    }

    std::queue<TreeNode *> node_queue;
    node_queue.push(root);
    int node_level = 0;

    while (!node_queue.empty()) {
        int ele_count = node_queue.size();
        std::vector<int> level_vec(ele_count);
        for (int i = 0; i < ele_count; i++) {
            TreeNode *cur_node = node_queue.front();
            node_queue.pop();
            if (node_level % 2) {
                level_vec[ele_count - 1 - i] = cur_node->val;
            } else {
                level_vec[i] = cur_node->val;
            }

            if (cur_node->left) {
                node_queue.push(cur_node->left);
            }

            if (cur_node->right) {
                node_queue.push(cur_node->right);
            }
        }

        node_level++;
        res_vec.push_back(level_vec);
    }

    return res_vec;
}