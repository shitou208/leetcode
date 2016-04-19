/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int get_depth(struct TreeNode* t);
    int res;
    res=get_depth(root);
    return res;
}

int get_depth(struct TreeNode* t){//递归思想
	//一个根节点，只要满足左右孩子中有一个不为NULL，则当前的层次就+1，
	if(t==NULL){return 0;}
	int left=get_depth(t->left);
	int right=get_depth(t->right);
	return (left>right)?left+1:right+1;
	//return (get_depth(t->left)>get_depth(t->right))?get_depth(t->left)+1:get_depth(t->right)+1;
	//这么写是错的，同一函数调用了两次，执行时间加倍！！
}