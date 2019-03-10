#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *result = new ListNode(0);
      ListNode *current = result;
      ListNode *currentL1 = l1;
      ListNode *currentL2 = l2;

      int next = 0;
      int sum = next + currentL1->val + currentL2->val;
      if (sum >= 10) {
        next = 1;
        sum %= 10;
      }
      current->val = sum;
      currentL1 = currentL1->next;
      currentL2 = currentL2->next;
      while (currentL1 != NULL || currentL2 != NULL) {
        int sum = next + (currentL1 != NULL ? currentL1->val : 0) + (currentL2 != NULL ? currentL2->val : 0);
        next = 0;
        if (sum >= 10) {
          next = 1;
          sum %= 10;
        }
        current->next = new ListNode(sum);
        current = current->next;
        currentL1 = currentL1 != NULL ? currentL1->next : NULL;
        currentL2 = currentL2 != NULL ? currentL2->next : NULL;
      }
      if (next > 0) {
        current->next = new ListNode(next);
      }
      return result;
    }
};

ListNode* intToList(int num) {
  ListNode *head = new ListNode(0);
  ListNode *current = head;

  current->val = num % 10;
  num /= 10;
  while (num != 0) {
    current->next = new ListNode(num % 10);
    // std::cout << "hank:" << current->val << std::endl;
    current = current->next;
    num /= 10;
  }
  return head;
}

void printList(ListNode *list) {
  ListNode *p = list;
  while (p != NULL) {
    std::cout << p->val;
    p = p->next;
  }
  std::cout << std::endl;
}

int main() {
  Solution sln;

  ListNode *left = intToList(1);
  printList(left);
  ListNode *right = intToList(999);
  printList(right);
  ListNode *result = sln.addTwoNumbers(left, right);
  printList(result);
  if (left != NULL) {
    delete left;
  }
  if (right != NULL) {
    delete right;
  }
  if (result != NULL) {
    delete result;
  }

  return 0;
}
