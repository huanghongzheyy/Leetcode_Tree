#include "tree.h"
#include <iostream>
using namespace std;

int main() {
	vector<int> nums = {1,2,2,3,4,4,3,5,NULL,NULL,6,6,NULL,NULL,5};
	TreeNode *root = buildTree(nums);
	cout << maxDepth_1(root) << endl;
	if (isSymmetric_2(root)) {
		cout << "This binary tree is sysmmetric!!!" << endl;
	}
	else
		cout << "This bianry tree is not sysmmetric!!!" << endl;
	return 0;
}