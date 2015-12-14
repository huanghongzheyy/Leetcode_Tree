#include "tree.h"
#include <iostream>
using namespace std;

int main() {
	vector<int> nums = {1,NULL,3,2,NULL,NULL,3,NULL,4,NULL,5};
	TreeNode *root = buildTree(nums);
	cout << maxDepth_1(root) << endl;
	return 0;
}