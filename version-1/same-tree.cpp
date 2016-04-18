/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    bool pre(struct TreeNode * t1, struct TreeNode * t2);
    if(!p || !q)
    {

        return (p == q) ? true : false;
    }
    return pre(p, q) ? true : false;
}

bool pre(struct TreeNode *t1, struct TreeNode *t2)
{
    //按照前序遍历来遍历整个二叉树，一边遍历一边比较
    if(t1 && t2) //在遍历过程中，一旦出现不相等的情况就结束，返回false
    {
        if(t1->val != t2->val)
        {
            return false;
        }
        if(!pre(t1->left, t2->left))
        {
            return false;
        }
        if(!pre(t1->right, t2->right))
        {
            return false;
        }
    }
    if((t1 && !t2) || (!t1 && t2))//如果出现，一个为空，一个不为空，则判定为不相等，返回false
    {
        return false;
    }
    else
    {
        return true;
    }
}