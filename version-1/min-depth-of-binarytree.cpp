/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 //本题和104题：max-depth类似
int minDepth(struct TreeNode *root)
{
    int get_depth(struct TreeNode * t);
    int res;
    if(!root)
    {
        return 0;
    }
    res = get_depth(root);
    return res;
}

int get_depth(struct TreeNode *t) //递归思想
{
    if(t == NULL)
    {
        return 0;
    }
    if(t->left == NULL || t->right == NULL) //至少有一个子树为空
    {
        int res = (t->left) ? get_depth(t->left) + 1 : get_depth(t->right) + 1;
        return res;
    }
    int left = get_depth(t->left);
    int right = get_depth(t->right);
    return (left < right) ? left + 1 : right + 1;
}