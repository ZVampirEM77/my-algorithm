#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> res_vec;
        if (root == nullptr) {
            return res_vec;
        }
    
        std::queue<TreeNode *> node_queue;
        node_queue.push(root);
        std::stack<std::vector<int>> res_stack;
        while (!node_queue.empty()) {
            int ele_count = node_queue.size();
            std::vector<int> level_vec;
            for (int i = 0; i < ele_count; i++) {
                TreeNode *cur_node = node_queue.front();
                node_queue.pop();
                level_vec.push_back(cur_node->val);
                if (cur_node->left) {
                    node_queue.push(cur_node->left);
                }
                if (cur_node->right) {
                    node_queue.push(cur_node->right);
                }
            }
            res_stack.push(level_vec);
        }
    
        int stack_size = res_stack.size();
        for (int i = 0; i < stack_size; i++) {
            res_vec.push_back(res_stack.top());
            res_stack.pop();
        }
    
        return res_vec;
    }


    int depth(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        return std::max(depth(node->left), depth(node->right)) + 1;
    }

    void levelOrder(std::vector<std::vector<int>> &res, TreeNode * node, uint32_t depth) {
        if (node == nullptr || depth <= 0) {
            return;
        }

        res[depth - 1].push_back(node->val);
        levelOrder(res, node->left, depth - 1);
        levelOrder(res, node->right, depth - 1);
    }

    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        int tree_depth = depth(root);
        std::vector<std::vector<int>> res_vec(tree_depth, std::vector<int>());
        levelOrder(res_vec, root, tree_depth);
        return res_vec;
    }