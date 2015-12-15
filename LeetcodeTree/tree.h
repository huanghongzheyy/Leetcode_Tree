#ifndef TREE_H
#define TREE_H
#include <vector>
//data structure about tree node
struct TreeNode {
	TreeNode * right;
	TreeNode *left;
	int val; 
	TreeNode(int);
};
//build tree by inputting a vector
TreeNode* buildTree(std::vector<int>& );
//get the max depth of tree in recursive method
int maxDepth_1(TreeNode*); 
//get the max depth of tree in iterated method
//int maxDepth_2(TreeNode*);
//get the lowest common ancestor of two tree nodes, a node can be a descendant of itself
TreeNode* lowestCommonAncestor(TreeNode*, TreeNode*, TreeNode*); //For Binary Search Tree (BST)
//check if a binary tree is balanced, please see more definition about balanced tree from leetcode.com
bool isBalanced(TreeNode*);
//check if a binary tree is symmetric (iterated method)
bool isSymmetric_1(TreeNode*);
#endif