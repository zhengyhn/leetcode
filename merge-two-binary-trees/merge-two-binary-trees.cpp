#include <iostream>
#include <stack>

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
      TreeNode *root = NULL;
      TreeNode *p1 = t1;
      TreeNode *p2 = t2;
      
      if (p1 != NULL && p2 != NULL) {
        int val = p1->val + p2->val;
        root = new TreeNode(val);
        root->left = this->mergeTrees(p1->left, p2->left);
        root->right = this->mergeTrees(p1->right, p2->right);
      } else if (p1 != NULL) {
        root = new TreeNode(p1->val);
        root->left = this->mergeTrees(p1->left, NULL);
        root->right = this->mergeTrees(p1->right, NULL);
      } else if (p2 != NULL) {
        root = new TreeNode(p2->val);
        root->left = this->mergeTrees(p2->left, NULL);
        root->right = this->mergeTrees(p2->right, NULL);
      }
      return root;
    }

    void preOrderTravel(TreeNode *tree) {
      TreeNode *p = tree;
      std::stack<TreeNode *> stack;

      while (p != NULL) {
        std::cout << p->val << " ";
        if (p->right != NULL) {
          stack.push(p->right);
        }
        p = p->left;
        if (p == NULL && !stack.empty()) {
          p = stack.top();
          stack.pop();
        }
      }
      std::cout << std::endl;
    }

    void destroy(TreeNode *tree) {
      TreeNode *p = tree;
      std::stack<TreeNode *> stack;

      while (p != NULL) {
        if (p->right != NULL) {
          stack.push(p->right);
        }
        TreeNode *toDelete = p;
        p = p->left;
        if (p == NULL && !stack.empty()) {
          p = stack.top();
          stack.pop();
        }
        delete toDelete;
      }
    }
};

int main() {
  Solution sln;
  // TreeNode *t1 = new TreeNode(1);
  // t1->left = new TreeNode(3);
  // t1->right = new TreeNode(2);
  // t1->left->left = new TreeNode(5);

  // TreeNode *t2 = new TreeNode(2);
  // t2->left = new TreeNode(1);
  // t2->right = new TreeNode(3);
  // t2->left->right = new TreeNode(4);
  // t2->right->right = new TreeNode(7);

  TreeNode *t1 = new TreeNode(1);
  t1->left = new TreeNode(2);
  t1->left->left = new TreeNode(3);

  TreeNode *t2 = new TreeNode(1);
  t2->right = new TreeNode(2);
  t2->right->right = new TreeNode(3);

  sln.preOrderTravel(t1);
  sln.preOrderTravel(t2);
  TreeNode *t3 = sln.mergeTrees(t1, t2);
  sln.preOrderTravel(t3);

  sln.destroy(t1);
  sln.destroy(t2);
  sln.destroy(t3);

  return 0;
}
