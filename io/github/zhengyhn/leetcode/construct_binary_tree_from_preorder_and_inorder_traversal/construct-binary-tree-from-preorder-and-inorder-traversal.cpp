#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return this->build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
  TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
    if (preStart == preEnd && inStart == inEnd && preorder[preStart] == preorder[inStart]) {
      return new TreeNode(preorder[preStart]);
    }
    if (preStart > preEnd || inStart > inEnd) {
      return NULL;
    }
    TreeNode *root = new TreeNode(preorder[preStart]);
    int i = (inStart + inEnd) >> 2;
    int j = i + 1;
    int rootIdx = inEnd + 1;
    for (; i >= inStart || j <= inEnd; ++j, --i) {
      if (i >= inStart && inorder[i] == preorder[preStart]) {
        rootIdx = i;
        break;
      }
      if (j <= inEnd && inorder[j] == preorder[preStart]) {
        rootIdx = j;
        break;
      }
    }
    root->left = this->build(preorder, preStart + 1, preStart + rootIdx - inStart,
                             inorder, inStart, rootIdx - 1);
    root->right = this->build(preorder, preStart + rootIdx - inStart + 1, preEnd,
                              inorder, rootIdx + 1, inEnd);

    return root;
  }

  void preOrder(TreeNode *root) {
    if (!root) {
      return;
    }
    cout << root->val << endl;
    this->preOrder(root->left);
    this->preOrder(root->right);
  }

  void inOrder(TreeNode *root) {
    if (!root) {
      return;
    }
    this->inOrder(root->left);
    cout << root->val << endl;
    this->inOrder(root->right);
  }
};

int main() {
  Solution sln;
  vector<int> preorder;
  vector<int> inorder;
  TreeNode* root;
  preorder = { 3, 9, 20, 15, 7 };
  inorder = { 9, 3, 15, 20, 7 };
  root = sln.buildTree(preorder, inorder);
  sln.preOrder(root);
  sln.inOrder(root);

  preorder = { 3 };
  inorder = { 3 };
  root = sln.buildTree(preorder, inorder);
  sln.preOrder(root);
  sln.inOrder(root);

  preorder = {};
  inorder = {};
  root = sln.buildTree(preorder, inorder);
  sln.preOrder(root);
  sln.inOrder(root);

  return 0;
}