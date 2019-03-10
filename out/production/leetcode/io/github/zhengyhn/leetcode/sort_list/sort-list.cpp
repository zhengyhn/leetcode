#include <iostream>

/* *
 *  * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* sortList(ListNode* head) {
      return sort(head);
    }
    
    ListNode *sort(ListNode *head) {
      if (head == NULL || head->next == NULL) {
        return head;
      }
      ListNode *p1, *p2;
      p1 =  head;
      p2 = head->next;
      while (p2 != NULL && p2->next != NULL) {
        p2 = p2->next;
        if (p2 == NULL) {
          break;
        }
        p2 = p2->next;
        p1 = p1->next;
      }
      p2 = sort(p1->next);
      p1->next = NULL;
      p1 = sort(head);
      //ListNode *p;
      //std::cout << "p1:";
      //p = p1;
      //while (p != NULL) {
      //  std::cout << p->val << " ";
      //  p = p->next;
      //}
      //std::cout << std::endl;
      //std::cout << "p2:";
      //p = p2;
      //while (p != NULL) {
      //  std::cout << p->val << " ";
      //  p = p->next;
      //}
      //std::cout << std::endl;
       
      return merge(p1, p2);
    }

    ListNode *merge(ListNode *left, ListNode *right) {
      ListNode *temp = new ListNode(0);
      ListNode *p = temp;

      ListNode *head, *pLeft, *pRight;

      pLeft = left;
      pRight = right;

      while (pLeft != NULL && pRight != NULL) {
        if (pLeft->val < pRight->val) {
          p->next = pLeft;
          pLeft = pLeft->next;
        } else {
          p->next = pRight;
          pRight = pRight->next;
        }
        p = p->next;
      }
      if (pLeft == NULL) {
        p->next = pRight;
      }
      if (pRight == NULL) {
        p->next = pLeft;
      }
      head = temp->next;
      temp->next = NULL;
      delete temp;

      return head;
    }
};

int main() {
  ListNode *list1 = new ListNode(4);
  ListNode *p = list1;
  p->next = new ListNode(19);
  p = p->next;
  p->next = new ListNode(14);
  p = p->next;
  p->next = new ListNode(5);
  p = p->next;
  p->next = new ListNode(-3);
  p = p->next;
  p->next = new ListNode(1);
  p = p->next;
  p->next = new ListNode(8);
  p = p->next;
  p->next = new ListNode(5);
  p = p->next;
  p->next = new ListNode(11);
  p = p->next;
  p->next = new ListNode(15);

  p = list1;
  while (p != NULL) {
    std::cout << p->val << std::endl;
    p = p->next;
  }

  Solution sln;
  p = sln.sortList(list1);

  while (p != NULL) {
    std::cout << p->val << std::endl;
    p = p->next;
  }
  return 0;
}
