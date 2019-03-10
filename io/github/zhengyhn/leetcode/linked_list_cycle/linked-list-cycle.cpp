#include <iostream>
#include <vector>
#include <unordered_map>

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
    bool hasCycle(ListNode *head) {
      ListNode *p1 = head;
      ListNode *p2 = head;
      while (p1 != NULL && p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
        if (p2 != NULL) {
          p2 = p2->next;
        } else {
          return false;
        }
        if (p1 == p2) {
          return true;
        }
      }
      return false;
    }
    bool hasCycleBrent(ListNode *head) {
      ListNode *p1 = head;
      ListNode *p2 = head;
      int steps = 0;
      int limit = 2;
      while (p1 != NULL && p2 != NULL) {
        p1 = p1->next;
        if (p1 == p2) {
          return true;
        }
        ++steps;
        if (steps == limit) {
          p2 = p1;
          steps = 0;
          limit *= 2;
        }
      }
      return false;
    }
};

int main() {
  Solution sln;
  ListNode *head = new ListNode(0);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = head;
  std::cout << sln.hasCycle(head) << std::endl;

  return 0;
}
