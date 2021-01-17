#include <iostream>
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
    vector<int> inorderTraversal(TreeNode* root) {
      if (root == NULL) {
        return {};
      }
      vector<int> ret;
      vector<TreeNode *> stack_next = {root};
      vector<TreeNode *> stack_visit;
      while (!stack_next.empty() || !stack_visit.empty()) {
        if (!stack_next.empty()) {
          TreeNode *top = stack_next.back();
          stack_next.pop_back();
          stack_visit.push_back(top);
          if (top->left) {
            stack_next.push_back(top->left);
          }
        } else {
          TreeNode *top = stack_visit.back();
          stack_visit.pop_back();
          ret.push_back(top->val);
          if (top->right) {
            stack_next.push_back(top->right);
          }
        }
      }
      return ret;
    }
    vector<int> inorderTraversal2(TreeNode* root) {
      if (root == NULL) {
        return {};
      }
      vector<TreeNode *> st;
      TreeNode *p = root;
      vector<int> ret;
      while (p != NULL || !st.empty()) {
        while (p != NULL) {
          st.push_back(p);
          p = p->left;
        }
        if (!st.empty()) {
          p = st.back();
          st.pop_back();
          ret.push_back(p->val);
          p = p->right;
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  vector<int> ret;
  ret = sln.inorderTraversal2(root);
  for (int item: ret) {
    cout << item << endl;
  }

  return 0;
}
