#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
      int sum = 0;
      vector<TreeNode *> stack;
      TreeNode *p = root;
      while (p != NULL || !stack.empty()) {
        while (p != NULL) {
          stack.push_back(p);
          p = p->left;
        }
        TreeNode *top = stack.back();
        stack.pop_back();
        if (top->val >= L && top->val <= R) {
          sum += top->val;
        } else if (top->val > R) {
          break;
        }
        if (top->right) {
          p = top->right;
        }
      }
      return sum;
    }
    int rangeSumBSTRecursive(TreeNode* root, int L, int R) {
      if (root == NULL) {
        return 0;
      }
      if (root->val > R) {
        return rangeSumBSTRecursive(root->left, L, R);
      } else if (root->val < L) {
        return rangeSumBSTRecursive(root->right, L, R);
      } else {
        return root->val + rangeSumBSTRecursive(root->left, L, root->val) + rangeSumBSTRecursive(root->right, root->val, R);
      }
    }
};

int main() {
    Solution sln;
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    cout << sln.rangeSumBST(root, 7, 15) << endl;
    cout << sln.rangeSumBSTRecursive(root, 7, 15) << endl;

    return 0;
}