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
    ListNode *p = NULL;
    while (!lists.empty()) {
      vector<ListNode *>::iterator end = lists.end();
      vector<ListNode *>::iterator min = end;
      vector<ListNode *>::iterator it = lists.begin();
      while (it != lists.end()) {
        if (*it == NULL) {
          it = lists.erase(it);
          continue;
        }
        if (min == end || (*it)->val < (*min)->val) {
          min = it;
        }
        ++it;
      }
      if (lists.empty()) {
        break;
      }
      if (p == NULL) {
        p = *min;
        dummy->next = p;
      } else {
        p->next = *min;
        p = p->next;
      }
      *min = (*min)->next;
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

  vector<ListNode *> lists = {NULL, head2, NULL};
  ListNode *head = sln.mergeKLists(lists);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}