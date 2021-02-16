#include <iostream>
#include <queue>

 typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 } TreeNode;


// 递归解法
 bool isSymmetric(TreeNode *root) {
     return isMirror(root, root);
 }

 bool isMirror(TreeNode *lt, TreeNode *rt) {
     if (lt == NULL && rt == NULL) {
         return true;
     } else if (lt == NULL || rt == NULL) {
         return false;
     }

     return (lt->val == rt->val) &&
            isMirror(lt->left, rt->right) &&
            isMirror(lt->right, rt->left);
 }

// 迭代解法

bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode *lt, TreeNode *rt) {
    std::queue<TreeNode *> tree_queue;
    tree_queue.push(lt);
    tree_queue.push(rt);
    while(!tree_queue.empty()) {
        TreeNode *t1 = tree_queue.front();
        tree_queue.pop();
        TreeNode *t2 = tree_queue.front();
        tree_queue.pop();
        if (t1 == NULL && t2 == NULL) {
            continue;
        } else if (t1 == NULL || t2 == NULL) {
            return false;
        } else if (t1->val != t2->val) {
            return false;
        }

        tree_queue.push(t1->left);
        tree_queue.push(t2->right);
        tree_queue.push(t1->right);
        tree_queue.push(t2->left);
    }

    return true;
}