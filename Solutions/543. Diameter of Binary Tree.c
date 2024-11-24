//
// Created by villi on 11/24/2024.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int res = 0;
int depth(struct TreeNode* root)
{
    if (!root)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    int diameter = left + right;

    if (diameter > res)
        res = diameter;

    return 1 + ((left > right) ? left : right);
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    res = 0;
    depth(root);
    return res;
}