#include <iostream>
#include <queue>
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
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *start = dummy;
    ListNode *nextStart = dummy;
    ListNode *end = head;
    while (end != NULL) {
      int i = 0;
      for (; i < k; ++i) {
        if (end != NULL) {
          end = end->next;
        } else {
          break;
        }
      }
      if (i < k) {
        break;
      }
      ListNode *p = start->next;
      nextStart = p;
      while (p->next != end) {
        ListNode *next = p->next;
        p->next = next->next;
        next->next = start->next;
        start->next = next;
        // start = start->next;
      }
      start = nextStart;
    }
    return dummy->next;
  }
};

int main() {
  Solution sln;
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(4);
  head1->next->next = new ListNode(5);
  head1->next->next->next = new ListNode(6);

  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(3);
  head2->next->next = new ListNode(4);

  ListNode *head3 = new ListNode(2);
  head3->next = new ListNode(6);

  ListNode *head = NULL;
  // head = sln.reverseKGroup(head1, 1);
  // while (head != NULL) {
  //   cout << head->val << " ";
  //   head = head->next;
  // }
  // cout << endl;

  head = sln.reverseKGroup(head1, 2);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  head = sln.reverseKGroup(head2, 3);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  return 0;
}