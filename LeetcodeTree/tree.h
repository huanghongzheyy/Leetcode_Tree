#ifndef TREE_H
#define TREE_H
#include <vector>
struct TreeNode {
	TreeNode * right;
	TreeNode *left;
	int val; 
	TreeNode(int);
};
TreeNode* buildTree(std::vector<int>& );
int maxDepth_1(TreeNode*);
//int maxDepth_2(TreeNode*);
TreeNode* lowestCommonAncestor(TreeNode*, TreeNode*, TreeNode*); //For Binary Search Tree (BST)
int getHeight(TreeNode*);
bool isBalanced(TreeNode*);
#endif