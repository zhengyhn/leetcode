#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    TreeNode *root = this->constructChildTree(nums, 0, nums.size() - 1);

    return root;
  }

  TreeNode* constructChildTree(vector<int>& nums, int start, int end) {
    if (start > end) {
      return NULL;
    }
    int maxIndex = start;
    for (int i = start; i <= end; ++i) {
      if (nums[i] > nums[maxIndex]) {
        maxIndex = i;
      }
    }
    TreeNode *root = new TreeNode(nums[maxIndex]);
    root->left = this->constructChildTree(nums, start, maxIndex - 1);
    root->right = this->constructChildTree(nums, maxIndex + 1, end);

    return root;
  }

  void preOrderTravel(TreeNode *tree) {
    TreeNode *p = tree;
    std::stack<TreeNode *> stack;

    while (p != NULL) {
      std::cout << p->val << " ";
      if (p->right != NULL) {
        stack.push(p->right);
      }
      p = p->left;
      if (p == NULL && !stack.empty()) {
        p = stack.top();
        stack.pop();
      }
    }
    std::cout << std::endl;
  }
};

int main() {
  Solution sln;
  const int size = 6;
  int arr[size] = {3,2,1,6,0,5};
  vector<int> vec(arr, arr + size);

  TreeNode *root = sln.constructMaximumBinaryTree(vec);
  std::cout << root->val << std::endl;
  sln.preOrderTravel(root);

  return 0;
}
