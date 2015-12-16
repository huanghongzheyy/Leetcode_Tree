#include "tree.h"
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
	for (int i = 1;i <= nums.size()-1;) {
		int f_size = fathers.size();
		int s_size = f_size * 2;
		int j =min ((i + s_size - 1), int(nums.size()-1)); //vector<>::size() is unsigned int type!
		while (i <= j) {
			TreeNode *now = fathers.front();
			fathers.pop();
			if (nums[i]) {
				TreeNode *left_son = new TreeNode(nums[i]);
				now->left = left_son;
				sons.push(left_son);
			}
			i++;
			if (i<=j && nums[i]) {
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

bool isBalanced(TreeNode *root) {
	if (root == NULL) return true;
	int left_height = maxDepth_1(root->left);  //call maxDepth() to get the depth
	int right_height = maxDepth_1(root->right);
	if (abs(left_height - right_height) > 1) return false;
	else return isBalanced(root->left) && isBalanced(root->right);
};

bool isSymmetric_1(TreeNode* root) {
	if (!root) return true; 
	queue<TreeNode*> queue_left;
	queue<TreeNode*> queue_right;
	if (!root->left && !root->right) {
		return true;
	}
	else if (root->left && root->right) {
		queue_left.push(root->left);
		queue_right.push(root->right);
	}
	else return false;
	
	do{
		if (queue_left.size() != queue_right.size()) return false;
		for (int i = queue_left.size();i > 0;i--) {
			TreeNode* node_left = queue_left.front();
			queue_left.pop();
			TreeNode* node_right = queue_right.front();
			queue_right.pop();
			if (node_left->val != node_right->val) return false;

			if ((!node_left->left && node_right->right) || (node_left->left && !node_right->right)) return false;
			else if (node_left->left && node_right->right) {
				queue_left.push(node_left->left);
				queue_right.push(node_right->right);
			}
			if ((!node_left->right && node_right->left) || (node_left->right && !node_right->left)) return false;
			else if (node_left->right && node_right->left) {
				queue_left.push(node_left->right);
				queue_right.push(node_right->left);
			}
		}

	} while (!queue_left.empty() && !queue_right.empty());
	return true;
};

bool isSymmetric_2(TreeNode* l_node, TreeNode* r_node){
	if(!l_node && !r_node) return true;
	else if((!l_node && r_node) || (!r_node && l_node)) return false;
	else{
		if(l_node->val!=r_node->val) return false;
		return isSymmetric_2(l_node->left,r_node->right) && isSymmetric_2(l_node->right,r_node->left);
	}
}
bool isSymmetric_2(TreeNode* root){
	if (!root) return true;
	else
		return isSymmetric_2(root->left,root->right);
}


