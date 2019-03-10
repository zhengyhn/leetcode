#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
      ListNode *leftHead = new ListNode(0);
      leftHead->next = NULL;
      ListNode *rightHead = NULL;
      ListNode *left = leftHead;
      ListNode *right = NULL;
      ListNode *p = head;
      while (p != NULL) {
        if (p->val < x) {
          if (leftHead->next == NULL) {
            leftHead->next = p;
            left = leftHead->next;
          } else {
            left->next = p;
            left = left->next;
          }
        } else {
          if (rightHead == NULL) {
            rightHead = p;
            right = rightHead;
          } else {
            right->next = p;
            right = right->next;
          }
        }
        p = p->next;
      }
      if (left != NULL) {
        left->next = rightHead;
      }
      if (right != NULL) {
        right->next = NULL;
      }

      return leftHead->next;
    }
};
int main() {
  Solution sln;
  ListNode *head;
  head = new ListNode(3);
  head->next = new ListNode(5);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(1);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next->next = new ListNode(5);
  ListNode *ret = sln.partition(head, 3);
  ListNode *p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  return 0;
}
