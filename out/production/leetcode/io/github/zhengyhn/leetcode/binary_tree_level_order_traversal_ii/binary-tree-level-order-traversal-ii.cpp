#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> ret;
      if (root == NULL) {
        return ret;
      }
      queue<TreeNode *> queue;
      queue.push(root);
      int parentSize = 1;
      int childSize = 0;
      while (!queue.empty()) {
        vector<int> list;
        while (parentSize > 0) {
          TreeNode *node = queue.front();
          list.push_back(node->val);
          queue.pop();
          if (node->left != NULL) {
            queue.push(node->left);
            ++childSize;
          }
          if (node->right != NULL) {
            queue.push(node->right);
            ++childSize;
          }
          --parentSize;
        }
        parentSize = childSize;
        childSize = 0;
        ret.insert(ret.begin(), list);
      }
      return ret;
    }
};

int main(void) {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  vector<vector<int>> ret = sln.levelOrderBottom(root);
  for (vector<int> it: ret) {
    for (int i: it) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
