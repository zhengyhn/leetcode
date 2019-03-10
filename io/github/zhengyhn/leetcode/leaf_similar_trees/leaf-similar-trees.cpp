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

class Solution {
  public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      stack<TreeNode *> s1;
      stack<TreeNode *> s2;
      s1.push(root1);
      s2.push(root2);
      while (!s1.empty() && !s2.empty()) {
        TreeNode *top1;
        while (!s1.empty()) {
          top1 = s1.top();
          s1.pop();
          if (top1->right != NULL) {
            s1.push(top1->right);
          }
          if (top1->left != NULL) {
            s1.push(top1->left);
          }
          if (top1->left == NULL && top1->right == NULL) {
            break;
          }
        }
        TreeNode *top2;
        while (!s2.empty()) {
          top2 = s2.top();
          s2.pop();
          if (top2->right != NULL) {
            s2.push(top2->right);
          }
          if (top2->left != NULL) {
            s2.push(top2->left);
          }
          if (top2->left == NULL && top2->right == NULL) {
            break;
          }
        }
        // cout << top1->val << " " << top2->val << endl;
        if (top1 == NULL || top2 == NULL) {
          return false;
        }
        if (top1->val != top2->val) {
          return false;
        }
      }
      return true;
    }
};

int main() {
  Solution sln;
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  TreeNode *root2 = new TreeNode(1);
  root2->right = new TreeNode(4);
  root2->right->left = new TreeNode(2);
  root2->right->right = new TreeNode(3);

  cout << sln.leafSimilar(root1, root2) << endl;

  return 0;
}
