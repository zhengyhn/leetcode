#include <iostream>
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
    bool isValidBST(TreeNode* root) {
      if (root == NULL) {
        return true;
      }
      bool isValid = this->isAllValid(root, true);
      if (!isValid) {
        return isValid;
      }
      isValid = this->isAllValid(root, false);
      if (!isValid) {
        return isValid;
      }
      isValid = this->isValidBST(root->left);
      if (!isValid) {
        return isValid;
      }
      isValid = this->isValidBST(root->right);

      return isValid;
    }

    bool isAllValid(TreeNode *root, bool isLeft) {
      bool isValid = true;
      std::stack<TreeNode *> st;

      if (isLeft) {
        if (root->left == NULL) {
          return true;
        } else {
          st.push(root->left);
        }
      } else {
        if (root->right == NULL) {
          return true;
        } else {
          st.push(root->right);
        }
      }
      while (st.size() > 0) {
        TreeNode *p = st.top();
        st.pop();
        isValid = isLeft ? (p->val < root->val) : (p->val > root->val);
        if (!isValid) {
          return isValid;
        }
        if (p->right != NULL) {
          st.push(p->right);
        }
        if (p->left != NULL) {
          st.push(p->left);
        }
      }
      return isValid;
    }

    bool isValidBST2(TreeNode* root) {
      if (root == NULL) {
        return true;
      }
      bool isValid = true;
      TreeNode *p = root;
      std::stack<TreeNode *> st;
      TreeNode *pre = NULL;

      while (p != NULL || !st.empty()) {
        while (p != NULL) {
          st.push(p);
          p = p->left;
        }
        p = st.top();
        st.pop();
        if (pre != NULL && pre->val >= p->val) {
          return false;
        }
        pre = p;
        p = p->right;
      }
      return isValid;
    }
};

int main() {
  Solution sln;

  TreeNode *t1 = new TreeNode(2);
  t1->left = new TreeNode(1);
  t1->right = new TreeNode(3);

  TreeNode *t2 = new TreeNode(1);
  t2->left = new TreeNode(2);
  t2->right = new TreeNode(3);

  TreeNode *t3 = new TreeNode(10);
  t3->left = new TreeNode(5);
  t3->right = new TreeNode(15);
  t3->right->left = new TreeNode(6);
  t3->right->right = new TreeNode(20);

  std::cout << sln.isValidBST2(t1) << std::endl;
  std::cout << sln.isValidBST2(t2) << std::endl;
  std::cout << sln.isValidBST2(t3) << std::endl;

  return 0;
}
