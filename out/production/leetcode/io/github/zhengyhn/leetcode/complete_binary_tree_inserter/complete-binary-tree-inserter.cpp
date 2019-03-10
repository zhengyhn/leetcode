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
class CBTInserter {
private:
  TreeNode *root;
  vector<TreeNode *> arr;
public:
    CBTInserter(TreeNode* root) {
      this->root = root;
      queue<TreeNode *> queue;
      queue.push(root);
      while (!queue.empty()) {
        TreeNode *front = queue.front();
        arr.push_back(front);
        queue.pop();
        if (front->left) {
          queue.push(front->left);
        }
        if (front->right) {
          queue.push(front->right);
        }
      }
    }
    
    int insert(int v) {
      TreeNode *node = new TreeNode(v);
      arr.push_back(node);
      int parentIdx = arr.size() % 2 ? (arr.size() - 2) / 2 : (arr.size() - 1) / 2;
      TreeNode *parent = arr[parentIdx];
      if (!parent->left) {
        parent->left = node;
      } else {
        parent->right = node;
      }
      return parent->val;
    }
    
    TreeNode* get_root() {
      return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
int main() {
  TreeNode *root = new TreeNode(1);
  CBTInserter *in = new CBTInserter(root);
  in->insert(2);
  TreeNode *r = in->get_root();

  return 0;
}
