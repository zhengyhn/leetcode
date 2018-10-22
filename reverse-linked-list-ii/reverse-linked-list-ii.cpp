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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      ListNode *dummy = new ListNode(0);
      dummy->next = head;
      ListNode *pPre = dummy;
      ListNode *p = pPre->next;
      for (int i = 1; i < m; ++i) {
        if (p == NULL) {
          return dummy->next;
        }
        pPre = pPre->next;
        p = pPre->next;
      }
      int count = n - m;
      while (count > 0 && p != NULL && p->next != NULL) {
        ListNode *temp = p->next->next;
        p->next->next = pPre->next;
        pPre->next = p->next;
        p->next = temp;

        --count;
      }
      return dummy->next;
    }
};

int main() {
  Solution sln;
  ListNode *head = NULL;
  ListNode *ret;
  ListNode *p;
  ret = sln.reverseBetween(head, 1, 2);
  p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  head = new ListNode(1);
  ret = sln.reverseBetween(head, 1, 2);
  p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  head = new ListNode(1);
  head->next = new ListNode(2);
  ret = sln.reverseBetween(head, 1, 2);
  p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  ret = sln.reverseBetween(head, 1, 2);
  p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  ret = sln.reverseBetween(head, 2, 3);
  p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  return 0;
}
