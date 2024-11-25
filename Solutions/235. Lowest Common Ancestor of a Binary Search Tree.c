//
// Created by villi on 11/25/2024.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int small = p->val < q->val ? p->val : q->val;
    int large = p->val > q->val ? p->val : q->val;

    while (root)
    {
        if (root->val > large)
            root = root->left;
        else if (root->val < small)
            root = root->right;
        else
            return root;
    }
}