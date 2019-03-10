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
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (root == NULL) {
      return root;
    }
    vector<int> inorder;
    TreeNode *p = root;
    stack<TreeNode *> st;
    while (p != NULL || !st.empty()) {
      if (p != NULL) {
        st.push(p);
        p = p->left;
      } else {
        p = st.top();
        st.pop();
        if (p->val >= L && p->val <= R) {
          inorder.push_back(p->val);
        }
        p = p->right;
      }
    }
    /// for (int item: inorder) {
    ///   std::cout << item << std::endl;
    /// }

    vector<int> preorder;
    p = root;
    while (p != NULL || !st.empty()) {
      if (p != NULL) {
        if (p->val >= L && p->val <= R) {
          preorder.push_back(p->val);
        }
        st.push(p);
        p = p->left;
      } else {
        p = st.top();
        st.pop();
        p = p->right;
      }
    }
    // for (int item: preorder) {
    //   std::cout << item << std::endl;
    // }
    TreeNode *newRoot = this->build(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);

    return newRoot;
  }

  TreeNode* build(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd) {
    if (preStart > preEnd || inStart > inEnd) {
      return NULL;
    }
    TreeNode *root = new TreeNode(preorder[preStart]);
    for (int i = inStart; inStart < inEnd; ++i) {
      if (inorder[i] == preorder[preStart]) {
        // std::cout << "left:" << inStart << " " << i << " " << preStart + 1 << " " << preStart + i - inStart + 1 << std::endl;
        // std::cout << "right:" << i + 1 << " " << inEnd << " " << preStart + i + 1 << " " << preEnd << std::endl;
        root->left = this->build(inorder, preorder, inStart, i - 1, preStart + 1, preStart + i - inStart);
        root->right = this->build(inorder, preorder, i + 1, inEnd, preStart + i - inStart + 1, preEnd);
        break;
      }
    }
    return root;
  }
};

int main() {
  Solution sln;
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(3);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(4);

  TreeNode *newRoot = sln.trimBST(root, 3, 6);
  TreeNode *p = newRoot;
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
  p = newRoot;
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
