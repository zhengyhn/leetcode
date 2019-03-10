#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ret;
      if (root == NULL) {
        return ret;
      }
      queue<TreeNode *> lastQueue;
      lastQueue.push(root);
      while (!lastQueue.empty()) {
        vector<int> temp;
        int size = lastQueue.size();
        for (int i = 0; i < size; ++i) {
          TreeNode *p = lastQueue.front();
          lastQueue.pop();
          temp.push_back(p->val);
          if (p->left != NULL) {
            lastQueue.push(p->left);
          }
          if (p->right != NULL) {
            lastQueue.push(p->right);
          }
        }
        ret.push_back(temp);
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
  vector<vector<int>> ret = sln.levelOrder(root);
  for (vector<int> arr: ret) {
    for (int item: arr) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
