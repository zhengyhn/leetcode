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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() <= 0) {
      return NULL;
    }
    queue<ListNode *> q;
    for (ListNode *item : lists) {
      q.push(item);
    }
    while (q.size() > 1) {
      ListNode *left = q.front();
      q.pop();
      ListNode *right = q.front();
      q.pop();
      q.push(this->mergeTwoLists(left, right));
    }
    return q.front();
  }

  ListNode *mergeTwoLists(ListNode *left, ListNode *right) {
    if (left == NULL) {
      return right;
    }
    if (right == NULL) {
      return left;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = left;
    ListNode *p = dummy;
    while (left != NULL && right != NULL) {
      if (right->val < left->val) {
        ListNode *temp = right->next;
        right->next = left;
        p->next = right;
        p = p->next;
        right = temp;
      } else {
        left = left->next;
        p = p->next;
      }
    }
    if (right != NULL) {
      p->next = right;
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