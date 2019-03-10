#include <iostream>
#include <queue>

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
    int minDepthMine(TreeNode* root) {
      if (root == NULL) {
        return 0;
      }
      if (root->left == NULL && root->right == NULL) {
        return 1;
      }
      queue<TreeNode *> first;
      queue<TreeNode *> second;
      vector<queue<TreeNode *>*> queues = {&first, &second};
      int idxQueue = 0;
      queue<TreeNode *> *pQueue = queues[idxQueue];
      pQueue->push(root);
      int depth = 0;
      queue<TreeNode *> *other = queues[(idxQueue + 1) % 2];
      while (!pQueue->empty()) {
        TreeNode *p = pQueue->front();
        pQueue->pop();
        if (p->left != NULL) {
          other->push(p->left);
        }
        if (p->right != NULL) {
          other->push(p->right);
        }
        if (p->left == NULL && p->right == NULL){
          return depth + 1;
        }
        if (pQueue->empty()) {
          idxQueue = (idxQueue + 1) % 2;
          pQueue = queues[idxQueue];
          other = queues[(idxQueue + 1) % 2];
          ++depth;
        }
      }
      return depth;
    }

    int minDepth(TreeNode *root) {
      if (root == NULL) {
        return 0;
      }
      queue<TreeNode *> q;
      q.push(root);
      int depth = 0;
      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
          TreeNode *p = q.front();
          q.pop();
          if (p->left) {
            q.push(p->left);
          }
          if (p->right) {
            q.push(p->right);
          }
          if (p->left == NULL && p->right == NULL) {
            return depth + 1;
          }
        }
        ++depth;
      }
      return depth;
    }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(4);

  std::cout << sln.minDepth(root) << std::endl;

  return 0;
}
