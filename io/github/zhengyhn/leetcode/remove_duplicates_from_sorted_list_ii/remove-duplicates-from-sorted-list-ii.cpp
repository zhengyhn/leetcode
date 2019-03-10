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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode *dummy = new ListNode(0);
      dummy->next = head;
      ListNode *p1 = dummy;
      ListNode *p2 = dummy->next;
      while (p2 != NULL && p2->next != NULL) {
        if (p2->val == p2->next->val) {
          while (p2->next != NULL && p2->val == p2->next->val) {
            ListNode *temp = p2->next;
            p2->next = temp->next;
            delete temp;
          }
          p1->next = p2->next;
          delete p2;
          p2 = p1->next;
        } else {
          p2 = p2->next;
          p1 = p1->next;
        }
      }
      return dummy->next;
    }
};

int main() {
  Solution sln;
  ListNode *head;
  head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next = new ListNode(5);
  ListNode *ret = sln.deleteDuplicates(head);
  ListNode *p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
  head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(2);
  head->next->next->next->next = new ListNode(3);
  ret = sln.deleteDuplicates(head);
  p = ret;
  while (p != NULL) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;

  return 0;
}
