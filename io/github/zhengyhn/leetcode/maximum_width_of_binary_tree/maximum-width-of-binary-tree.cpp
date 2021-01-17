#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

struct IndentTreeNode {
  TreeNode *node;
  unsigned long long indent;
  IndentTreeNode(TreeNode *n, unsigned long long i) : node(n), indent(i) {}
};
class Solution {
 public:
  int widthOfBinaryTree(TreeNode *root) {
    if (!root) {
      return 0;
    }
    queue<IndentTreeNode *> q;
    q.push(new IndentTreeNode(root, 1));
    unsigned long long maxWidth = 1;
    while (!q.empty()) {
      int len = q.size();
      IndentTreeNode *first = q.front();
      IndentTreeNode *last;
      for (int i = 0; i < len; ++i) {
        IndentTreeNode *front = q.front();
        last = front;
        q.pop();
        if (front->node->left) {
          q.push(new IndentTreeNode(front->node->left, 2 * front->indent + 1));
        }
        if (front->node->right) {
          q.push(new IndentTreeNode(front->node->right, 2 * front->indent + 2));
        }
      }
      maxWidth = max(maxWidth, last->indent - first->indent + 1);
    }
    return maxWidth;
  }
};