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
      root = st.top();
      st.pop();
      result.insert(result.begin(), root->val);
      if (root->left) {
        st.push(root->left);
      }
      if (root->right) {
        st.push(root->right);
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
