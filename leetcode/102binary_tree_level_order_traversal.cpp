#include <iostream>
#include <vector>
#include <queue>

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res_vec;
    if (root == NULL) {
        return res_vec;
    }

    std::queue<TreeNode *> node_queue;
    node_queue.push(root);
    std::queue<TreeNode *> processing_queue;
    while (!node_queue.empty()) {
        processing_queue.swap(node_queue);
        std::vector<int> level_vec;
        int ele_count = processing_queue.size();
        for (int i = 0; i < ele_count; i++) {
            TreeNode *cur_node = processing_queue.front();
            processing_queue.pop();
            level_vec.push_back(cur_node->val);
            if (cur_node->left) {
                node_queue.push(cur_node->left);
            }
            if (cur_node->right) {
                node_queue.push(cur_node->right);
            }
        }
        res_vec.push_back(level_vec);
    }

    return res_vec;
}