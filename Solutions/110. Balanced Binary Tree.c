//
// Created by villi on 11/24/2024.
//

#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int depth(struct TreeNode* root)
{
    if (!root)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    if (left == -1 || right == -1)
        return -1;

    if (left > right + 1 || right > left + 1)
        return -1;

    return ((left > right) ? left : right) + 1;
}

bool isBalanced(struct TreeNode* root)
{
    if (depth(root) == -1)
        return false;
    return true;
}
