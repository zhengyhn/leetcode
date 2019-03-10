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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode *root = this->build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);

    return root;
  }

  TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (postStart > postEnd || inStart > inEnd) {
      return NULL;
    }
    TreeNode *root = new TreeNode(postorder[postEnd]);
    for (int i = inStart; inStart < inEnd; ++i) {
      if (inorder[i] == postorder[postEnd]) {
        // std::cout << "left:" << inStart << " " << i - 1 << " " << postStart << " " << postEnd - (inEnd - i) - 1 << std::endl;
        // std::cout << "right:" << i + 1 << " " << inEnd << " " << postEnd - (inEnd - i) << " " << postEnd << std::endl;
        root->left = this->build(inorder, postorder, inStart, i - 1, postStart, postEnd - (inEnd - i) - 1);
        root->right = this->build(inorder, postorder, i + 1, inEnd, postEnd - (inEnd - i), postEnd - 1);
        break;
      }
    }
    return root;
  }
};

int main() {
  Solution sln;

  vector<int> inorder = {1, 3, 4, 5, 6, 7};
  vector<int> postorder = {1, 4, 5, 3, 7, 6};
  TreeNode *root = sln.buildTree(inorder, postorder);
  TreeNode *p = root;
  stack<TreeNode *> st;
  while (p != NULL || !st.empty()) {
    if (p != NULL) {
      st.push(p);
      p = p->left;
    } else {
      p = st.top();
      st.pop();
      std::cout << p->val << std::endl;
      p = p->right;
    }
  }
  p = root;
  st.push(p);
  while (!st.empty()) {
    p = st.top();
    st.pop();
    std::cout << p->val << std::endl;
    if (p->right != NULL) {
      st.push(p->right);
    }
    if (p->left != NULL) {
      st.push(p->left);
    }
  }

  return 0;
}
