#include <iostream>
#include <vector>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head == NULL) {
        return head;
      }
      ListNode *p1 = head;
      ListNode *p2 = head;
      int i = 0;
      while (i++ < n) {
        p2 = p2->next;
      }
      while (p2 != NULL && p2->next != NULL) {
        p2 = p2->next;
        p1 = p1->next;
      }
      if (p1 == head && p2 == NULL) {
        head = p1->next;
      } else {
        p1->next = p1->next->next;
      }

      return head;
    }
};

int main() {
  Solution sln;
  ListNode *head = new ListNode(1);
  ListNode *p = head;
  // for (int i = 1; i < 5; ++i) {
  //   p->next = new ListNode(i + 1);
  //   p = p->next;
  // }
  ListNode *ret = sln.removeNthFromEnd(head, 1);
  p = ret;
  while (p != NULL) {
    std::cout << p->val << " ";
    p = p->next;
  }
  std::cout << std::endl;

  return 0;
}
