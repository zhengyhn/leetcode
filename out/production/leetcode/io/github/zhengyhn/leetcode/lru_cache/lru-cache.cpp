#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int value;
  int key;
  Node *prev;
  Node *next;
  Node(int k, int v, Node *p, Node *n) : key(k), value(v), prev(p), next(n) {}
};

class LRUCache {
 private:
  unordered_map<int, Node *> map;
  Node *tail;
  int capacity;
  int size;
  void update(Node *node) {
    Node *prev = node->prev;
    prev->next = node->next;
    if (node->next != NULL) {
      node->next->prev = prev;
    }
    prev = tail->prev;
    prev->next = node;
    node->prev = prev;
    node->next = tail;
    tail->prev = node;
  }

 public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->tail = new Node(-1, -1, NULL, NULL);
    this->tail->prev = this->tail;
    this->tail->next = this->tail;
    this->size = 0;
  }

  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    }
    Node *node = map[key];
    if (node == NULL) {
      return -1;
    }
    update(node);
    return node->value;
  }

  void put(int key, int value) {
    if (map.find(key) != map.end() && map[key] != NULL) {
      Node *node = map[key];
      node->value = value;
      update(node);
    } else {
      Node *node = new Node(key, value, tail->prev, tail);
      map[key] = node;
      Node *prev = tail->prev;
      tail->prev = node;
      prev->next = node;
      ++size;
      if (this->size > this->capacity) {
        Node *head = tail->next;
        tail->next = head->next;
        head->next->prev = tail;
        map[head->key] = NULL;
        delete head;
        --size;
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache *obj = new LRUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  cout << obj->get(1) << endl;
  obj->put(3, 3);
  cout << obj->get(2) << endl;
  obj->put(4, 4);
  cout << obj->get(1) << endl;
  cout << obj->get(3) << endl;
  cout << obj->get(4) << endl;
}