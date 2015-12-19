#include "tree.h"
using namespace std;

int main() {
	int num[]={1,2,2,3,4,4,3,5,NULL,NULL,6,6,NULL,NULL,5};
	size_t size=sizeof(num)/sizeof(int);
	vector<int> nums (num,num+size);  //initialized with an array
	TreeNode *root = buildTree(nums);
	//cout << maxDepth_1(root) << endl;
	if (isSymmetric_2(root)) {
		cout << "This binary tree is sysmmetric!!!" << endl;
	}
	else
		cout << "This bianry tree is not sysmmetric!!!" << endl;
	return 0;
}