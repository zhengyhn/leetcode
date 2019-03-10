#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> ret;
      if (root == NULL) {
        return ret;
      }
      queue<TreeNode *> lastQueue;
      queue<TreeNode *> nextQueue;
      lastQueue.push(root);
      bool leftToRight = true;
      while (!nextQueue.empty() || !lastQueue.empty()) {
        if (leftToRight) {
          vector<int> temp;
          while (!lastQueue.empty()) {
            TreeNode *p = lastQueue.front();
            lastQueue.pop();
            temp.push_back(p->val);
            if (p->left != NULL) {
              nextQueue.push(p->left);
            }
            if (p->right != NULL) {
              nextQueue.push(p->right);
            }
          }
          ret.push_back(temp);
          leftToRight = false;
        } else {
          vector<int> temp;
          while (!nextQueue.empty()) {
            TreeNode *p = nextQueue.front();
            nextQueue.pop();
            temp.insert(temp.begin(), p->val);
            if (p->left != NULL) {
              lastQueue.push(p->left);
            }
            if (p->right != NULL) {
              lastQueue.push(p->right);
            }
          }
          ret.push_back(temp);
          leftToRight = true;
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  vector<vector<int>> ret = sln.zigzagLevelOrder(root);
  for (vector<int> arr: ret) {
    for (int item: arr) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
