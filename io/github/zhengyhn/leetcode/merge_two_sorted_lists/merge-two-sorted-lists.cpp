#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *p1 = l1;
      ListNode *p2 = l2;
      ListNode *root = NULL;
      if (p1 == NULL) {
        root = p2;
      } else if (p2 == NULL) {
        root = p1;
      } else {
        if (p1->val < p2->val) {
          root = p1;
        } else {
          root = p2;
        }
      }
      if (root == NULL) {
        return root;
      } else if (root == p1) {
        p1 = p1->next;
      } else if (root == p2) {
        p2 = p2->next;
      }

      ListNode *p = root;
      while (p1 != NULL && p2 != NULL) {
        if (p1->val < p2->val) {
          p->next = p1;
          p1 = p1->next;
        } else {
          p->next = p2;
          p2 = p2->next;
        }
        p = p->next;
      }
      while (p1 != NULL) {
        p->next = p1;
        p1 = p1->next;
        p = p->next;
      }
      while (p2 != NULL) {
        p->next = p2;
        p2 = p2->next;
        p = p->next;
      }
      return root;
    }
};
int main() {
  Solution sln;
  ListNode *p1 = new ListNode(1);
  p1->next = new ListNode(2);
  p1->next->next = new ListNode(4);

  ListNode *p2 = new ListNode(1);
  p2->next = new ListNode(3);
  p2->next->next = new ListNode(4);
  ListNode *root = sln.mergeTwoLists(p1, p2);
  while (root != NULL) {
    std::cout << root->val << std::endl;
    root = root->next;
  }

  return 0;
}
