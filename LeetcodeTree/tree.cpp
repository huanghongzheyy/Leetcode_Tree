#include "tree.h"
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

TreeNode::TreeNode(int i) {
	this->left = NULL;
	this->right = NULL;
	this->val = i;
};
TreeNode* buildTree(vector<int>& nums) {
	if (nums.size() == 0) return NULL;
	queue<TreeNode*> fathers;
	queue<TreeNode *> sons;
	TreeNode *root = new TreeNode(nums[0]);
	fathers.push(root);
	for (int i = 1;i < nums.size();) {
		int f_size = fathers.size();
		int s_size = f_size * 2;
		int j =min ((i + s_size - 1), int(nums.size()-1)); //vector<>::size() is unsigned int type!
		while (i <= j) {
			TreeNode *now = fathers.front();
			fathers.pop();
			if (nums[i]!=NULL) {
				TreeNode *left_son = new TreeNode(nums[i]);
				now->left = left_son;
				sons.push(left_son);
			}
			i++;
			if (i<=j && nums[i]!=NULL) {
				TreeNode *right_son = new TreeNode(nums[i]);
				now->right = right_son;
				sons.push(right_son);
			}
			i++;
		}
		fathers.swap(sons);
	}
	return root;
};
int maxDepth_1(TreeNode* root) {
	
	if(root==NULL) return 0;
	return max(maxDepth_1(root->left),maxDepth_1(root->right))+1;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	int root_value = root->val;
	int p_value = p->val;
	int q_value = q->val;
	if ((p_value >= root_value && q_value <= root_value) || (p_value <= root_value && q_value >= root_value)) {
		return root;
	}
	else if (p_value>=root_value && q_value >= root_value) 
		return lowestCommonAncestor(root->right, p, q);
	else if(p_value <= root_value && q_value <= root_value)
		return lowestCommonAncestor(root->left, p, q);
};