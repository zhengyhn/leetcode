#include <iostream>
#include <deque>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      }
      int depth = 0;
      deque<TreeNode *> queue;
      queue.push_back(root);
      queue.push_back(NULL);
      while (queue.size() > 1) {
        TreeNode *node = NULL;
        if (queue.front() != NULL) {
          while (queue.front() != NULL) {
            node = queue.front();
            queue.pop_front();
            if (node->left != NULL) {
              queue.push_back(node->left);
            }
            if (node->right != NULL) {
              queue.push_back(node->right);
            }
          }
          ++depth;
        } else if (queue.back() != NULL) {
          while (queue.back() != NULL) {
            node = queue.back();
            queue.pop_back();
            if (node->left != NULL) {
              queue.push_front(node->left);
            }
            if (node->right != NULL) {
              queue.push_front(node->right);
            }
          }
          ++depth;
        }
      }
      return depth;
    }
};

int main(void) {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(2);
  std::cout << sln.maxDepth(root) << std::endl;

  return 0;
}
