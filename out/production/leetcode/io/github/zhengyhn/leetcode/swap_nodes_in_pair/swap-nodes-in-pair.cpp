#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* swapPairs(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode *dummy = new ListNode(0);
      dummy->next = head;
      ListNode *p1 = dummy;
      ListNode *p2 = p1->next;
      ListNode *p3 = p2->next;
      while (p2 != NULL && p3 != NULL) {
        p2->next = p3->next;
        p3->next = p2;
        p1->next = p3;
        ListNode *temp = p3;
        p3 = p2;
        p2 = temp;
        p3 = p3->next;
        p2 = p2->next;
        p1 = p1->next;
        if (p3 == NULL) {
          break;
        }
        p3 = p3->next;
        p2 = p2->next;
        p1 = p1->next;
      }
      return dummy->next;
    }
};

int main() {
  Solution sln;
  ListNode *head = new ListNode(1);
  ListNode *p = head;
  for (int i = 1; i < 10; ++i) {
    p->next = new ListNode(i + 1);
    p = p->next;
  }
  ListNode *ret = sln.swapPairs(head);
  p = ret;
  while (p != NULL) {
    std::cout << p->val << " ";
    p = p->next;
  }
  std::cout << std::endl;

  return 0;
}
