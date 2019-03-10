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
    ListNode *detectCycle(ListNode *head) {
      ListNode *p1 = head;
      ListNode *p2 = head;
      ListNode *temp = NULL;
      while (p1 != NULL && p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
        if (p2 != NULL) {
          p2 = p2->next;
        } else {
          return NULL;
        }
        if (p1 == p2) {
          temp = p1;
          p1 = head;
          while (p1 != temp) {
            p1 = p1->next;
            p2 = temp->next;
            while (p2 != temp) {
              if (p1 == p2) {
                return p1;
              }
              p2 = p2->next;
            }
          }
          return p1;
        }
      }
      return NULL;
    }
    ListNode *detectCycle2(ListNode *head) {
      if (head == NULL) {
        return head;
      }
      unordered_map<ListNode *, ListNode *> map;
      ListNode *p = head;
      map[p] = NULL;
      while (p->next != NULL) {
        if (map.find(p->next) != map.end()) {
          return p->next;
        }
        map[p->next] = p; 
        p = p->next;
      }
      return NULL;
    }

    ListNode *detectCycle3(ListNode *head) {
      ListNode *p1 = head;
      ListNode *p2 = head;
      ListNode *entry = head;
      while (p1 != NULL && p2 != NULL) {
        p1 = p1->next;
        p2 = p2->next;
        if (p2 != NULL) {
          p2 = p2->next;
        } else {
          return NULL;
        }
        if (p1 == p2) {
          while (p1 != entry) {
            p1 = p1->next;
            entry = entry->next;
          }
          return entry;
        }
      }
      return NULL;
    }
};

int main() {
  Solution sln;
  // ListNode *head = new ListNode(3);
  // head->next = head;
  // ListNode *head = new ListNode(3);
  // head->next = new ListNode(2);
  // head->next->next = new ListNode(-4);
  // head->next->next->next = head->next;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = head;
  std::cout << (sln.detectCycle3(head))->val << std::endl;

  return 0;
}
