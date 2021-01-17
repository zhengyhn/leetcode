#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() <= 0) {
      return NULL;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = lists[0];
    for (int i = 1; i < lists.size(); ++i) {
      ListNode *p1 = dummy;
      ListNode *p2 = p1->next;
      ListNode *p = lists[i];
      while (p != NULL && p2 != NULL) {
        if (p->val < p2->val) {
          ListNode *temp = p->next;
          p->next = p2;
          p1->next = p;
          p1 = p;
          p = temp;
        } else {
          p1 = p2;
          p2 = p1->next;
        }
      }
      if (p2 == NULL) {
        p1->next = p;
      }
    }
    return dummy->next;
  }
};

int main() {
  Solution sln;
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(4);
  head1->next->next = new ListNode(5);

  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(3);
  head2->next->next = new ListNode(4);

  ListNode *head3 = new ListNode(2);
  head3->next = new ListNode(6);

  vector<ListNode *> lists = {head1, head2, head3};
  ListNode *head = sln.mergeKLists(lists);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}