#include <semaphore.h>

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Foo {
 private:
  sem_t *sem1;
  sem_t *sem2;

 public:
  Foo() {
    sem1 = sem_open("sem1", O_CREAT | O_EXCL, S_IRWXU, 0);
    sem2 = sem_open("sem2", O_CREAT | O_EXCL, S_IRWXU, 0);
    // sem_init(&sem1, 0, 0);
    // sem_init(&sem2, 0, 0);
  }

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(sem1);
  }

  void second(function<void()> printSecond) {
    sem_wait(sem1);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(sem2);
  }

  void third(function<void()> printThird) {
    sem_wait(sem2);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};

void print(Foo &foo, int i) {
  switch (i) {
    case 1:
      foo.first([]() { cout << "first"; });
      break;
    case 2:
      foo.second([]() { cout << "second"; });
      break;
    case 3:
      foo.third([]() { cout << "third"; });
      break;
    default:
      break;
  }
}

int main() {
  vector<int> nums = {1, 3, 2};
  thread list[nums.size()];
  Foo foo;

  for (int i = 0; i < nums.size(); ++i) {
    list[i] = thread(print, std::ref(foo), nums[i]);
  }
  for (auto &t : list) {
    t.join();  // 等待线程执行完成
  }
  return 0;
}