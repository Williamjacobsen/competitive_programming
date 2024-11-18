//
// Created by villi on 11/18/2024.
//

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
    if (!root)
        return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + ((left > right) ? left : right);
}
