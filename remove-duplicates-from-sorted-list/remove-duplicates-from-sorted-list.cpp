#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode *p1, *p2;
      p1 = head;
      p2 = head->next;
      while (p2 != NULL) {
        if (p2->val == p1->val) {
          p1->next = p2->next;
          delete p2;
          p2 = p1->next;
        } else {
          p1 = p2;
          p2 = p2->next;
        }
      }
      return head;
    }
};

int main(void) {
  Solution sln;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  ListNode *ret = sln.deleteDuplicates(head);
  while (ret != NULL) {
    std::cout << ret->val << std::endl;
    ret = ret->next;
  }

  return 0;
}
