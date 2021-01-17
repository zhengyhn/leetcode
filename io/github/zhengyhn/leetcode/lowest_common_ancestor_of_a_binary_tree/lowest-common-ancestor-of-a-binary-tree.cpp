#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int value;
  TreeNode *left;
  TreeNode *right;

 public:
  TreeNode(int val) : value(val) {}
};

class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    stack<TreeNode *> ancestors;
    stack<TreeNode *> st;
    TreeNode *temp = root;
    bool foundOne = false;
    TreeNode *recent;
    while (temp || !st.empty()) {
      if (temp) {
        st.push(temp);
        if (!foundOne) {
          ancestors.push(temp);
        }
        temp = temp->left;
      } else {
        TreeNode *top = st.top();
        if (top->right && top->right != recent) {
          temp = top->right;
        } else {
          if (top == p || top == q) {
            if (!foundOne) {
              foundOne = true;
            } else {
              while (top != ancestors.top()) {
                st.pop();
                top = st.top();
              }
              return top;
            }
          }
          st.pop();
          if (top == ancestors.top()) {
            ancestors.pop();
          }
          recent = top;
          temp = NULL;
        }
      }
    }
    return root;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  // root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  // root->right->left = new TreeNode(6);
  TreeNode *r;
  // sln.ancestor(root, root->left->left, root->left, &r);
  // cout << r->value << endl;
  r = sln.lowestCommonAncestor(root, root->left, root->left->right);
  cout << r->value << endl;

  return 0;
}