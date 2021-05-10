#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) return;

		return std::max( maxDepth( root->left ), maxDepth( root->right ) ) + 1;
	}
};

int main()
{

	return 0;
}