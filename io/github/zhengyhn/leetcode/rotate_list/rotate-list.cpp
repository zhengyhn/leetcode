#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
      if (head == NULL || head->next == NULL || k == 0) {
        return head;
      }
      int len = 0;
      ListNode *p = head;
      while (p != NULL) {
        ++len;
        p = p->next;
      }
      k %= len;
      if (k == 0) {
        return head;
      }
      ListNode *dummy = new ListNode(-1);
      dummy->next = head;
      ListNode *p1 = dummy;
      for (int i = 0; i < k; ++i) {
        p1 = p1->next;
        if (p1 == NULL) {
          p1 = dummy->next;
        }
      }
      ListNode *p2 = dummy;
      while (p1->next != NULL) {
        p2 = p2->next;
        p1 = p1->next;
      }
      if (p2 == dummy) {
        return dummy->next;
      }
      ListNode *temp = dummy->next;
      dummy->next = p2->next;
      p2->next = NULL;
      ListNode *p3 = dummy->next;
      while (p3->next != NULL) {
        p3 = p3->next;
      }
      p3->next = temp;
      return dummy->next;
    }
};

int main() {
  Solution sln;
  ListNode *root = NULL;
  root = new ListNode(1);
  root->next = new ListNode(2);
  // root->next->next = new ListNode(3);
  ListNode *ret = sln.rotateRight(root, 2);
  ListNode *p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  return 0;
}
