#include <iostream>
#include <stack>
#include <vector>

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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == NULL) {
      return result;
    }
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      while (root->left != NULL) {
        TreeNode *left = root->left;
        st.push(left);
        root->left = NULL;
        root = left;
      }
      root = st.top();
      if (root->right) {
        TreeNode *right = root->right;
        st.push(right);
        root->right = NULL;
        root = right;
      } else {
        result.push_back(root->val);
        st.pop();
      }
    }
    return result;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  vector<int> ret;
  ret = sln.postorderTraversal(root);
  for (int item : ret) {
    cout << item << endl;
  }

  return 0;
}
