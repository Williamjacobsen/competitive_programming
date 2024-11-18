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