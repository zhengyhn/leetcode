#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      if (nums.size() <= 0) {
        return NULL;
      }
      if (nums.size() == 1) {
        TreeNode *node = new TreeNode(nums[0]);
        return node;
      }
      int middle = nums.size() / 2;
      TreeNode *root = new TreeNode(nums[middle]);
      vector<int> left(nums.begin(), nums.begin() + middle); 
      vector<int> right(nums.begin() + middle + 1, nums.end()); 
      root->left = sortedArrayToBST(left);
      root->right = sortedArrayToBST(right);

      return root;
    }
};

int main() {
  Solution sln;
  vector<int> nums = {-10,-3,0,5,9};
  TreeNode *root = sln.sortedArrayToBST(nums);
  std::cout << root->val << std::endl;
  std::cout << root->left->val << std::endl;
  std::cout << root->right->val << std::endl;
  std::cout << root->left->left->val << std::endl;
  std::cout << root->right->left->val << std::endl;

  return 0;
}
