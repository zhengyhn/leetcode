#include <iostream>
#include <map>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList1(RandomListNode *head) {
      if (head == NULL) {
        return NULL;
      }
      RandomListNode *p = head;

      while (p != NULL) {
        RandomListNode *newNode = new RandomListNode(p->label);
        newNode->next = p->next;
        p->next = newNode;
        p = newNode->next;
      }

      p = head;
      while (p != NULL) {
        if (p->random != NULL) {
          p->next->random = p->random->next;
        } else {
          p->next->random = NULL;
        }
        p = p->next->next;
      }

      p = head;
      RandomListNode *newHead = p->next;
      RandomListNode *p2;
      p->next = newHead->next;
      p2 = newHead;
      p = p->next;
      while (p != NULL) {
        p2->next = p->next;
        p2 = p2->next;
        p->next = p2->next;
        p = p->next;
      }

      return newHead;
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
      if (head == NULL) {
        return NULL;
      }
      RandomListNode *newHead = new RandomListNode(head->label); 
      RandomListNode *pNew, *pOld;
      std::map<RandomListNode *, RandomListNode *> map;

      map.insert(std::pair<RandomListNode *, RandomListNode *>(
            head, newHead));
      pNew = newHead;
      pOld = head->next;
      while (pOld != NULL) {
        pNew->next = new RandomListNode(pOld->label);
        pNew = pNew->next;
        map.insert(std::pair<RandomListNode *, RandomListNode *>(
              pOld, pNew));
        pOld = pOld->next;
      }

      pOld = head;
      pNew = newHead;
      while (pOld != NULL) {
        if (pOld->random != NULL) {
          pNew->random = map[pOld->random];
        } else {
          pNew->random = NULL;
        }
        pOld = pOld->next;
        pNew = pNew->next;
      }
      return newHead;
    }
};

int main() {
  Solution sln;
  RandomListNode *p;
  RandomListNode *head = new RandomListNode(1);
  head->random = head;
  p = head;
  p->next = new RandomListNode(2);
  p = p->next;
  p->random = head;
  p->next = new RandomListNode(3);
  p = p->next;
  p->random = NULL;
  p->next = new RandomListNode(4);
  p = p->next;
  p->random = NULL;
  head->next->next->random = p;

  p = head;
  while (p != NULL) {
    std::cout << p << " " << p->label << " " << p->random << std::endl;
    p = p->next;
  }
  std::cout << "---------------------------\n";

  RandomListNode *newHead = sln.copyRandomList1(head);
  p = newHead;
  while (p != NULL) {
    std::cout << p << " " << p->label << " " << p->random << std::endl;
    p = p->next;
  }

  p = newHead;
  while (p != NULL) {
    RandomListNode *temp = p;
    p = p->next;
    delete temp;
  }

  p = head;
  while (p != NULL) {
    RandomListNode *temp = p;
    p = p->next;
    delete temp;
  }

  return 0;
}
