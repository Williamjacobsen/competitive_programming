//
// Created by villi on 11/18/2024.
//

#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (!p && !q)
        return true;
    if (!p || !q || p->val != q->val)
        return false;

    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (!root)
        return false;
    if (!subRoot)
        return true;

    if (isSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}