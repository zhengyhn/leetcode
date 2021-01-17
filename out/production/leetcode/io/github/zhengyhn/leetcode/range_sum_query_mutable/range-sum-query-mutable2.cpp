#include <iostream>
#include <vector>

using namespace std;

class NumArray
{
private:
  vector<int> nums;
  vector<int> bits;

  int getLowBit(int n) {
    return n & (-n);
  }

  void add(int i, int val) {
    for (int j = i; j < this->bits.size(); j += this->getLowBit(j))
    {
      this->bits[j] += val;
    }
  }

  int query(int i) {
    int sum = 0;
    for (int j = i; j >= 1; j -= this->getLowBit(j)) {
      sum += this->bits[j];
    }
    return sum;
  }
public:
  NumArray(vector<int> nums)
  {
    this->nums = nums;
    this->bits = vector<int>(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); ++i) {
      this->add(i, nums[i - 1]);
    }
  }

  void update(int i, int val)
  {
    this->add(i + 1, val - this->nums[i]);
    this->nums[i] = val;
  }

  int sumRange(int i, int j)
  {
    return this->query(j + 1) - this->query(i);
  }
  void print() {
    for (int num: this->bits) {
      cout << num << " ";
    }
    cout << endl;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main()
{
  vector<int> nums;
  // nums = {1, 3, 5};
  // NumArray numArray(nums);
  // cout << numArray.sumRange(0, 2) << endl;
  // numArray.update(0, 2);
  // cout << numArray.sumRange(0, 0) << endl;
  // numArray.update(2, 6);
  // cout << numArray.sumRange(0, 1) << endl;
  // cout << numArray.sumRange(1, 2) << endl;
  // cout << numArray.sumRange(2, 2) << endl;

  nums = {7, 2, 7, 2, 0};
  NumArray numArray(nums);
  numArray.print();
  numArray.update(4, 6);
  numArray.print();
  numArray.update(0, 2);
  numArray.print();
  numArray.update(0, 9);
  numArray.print();
  cout << numArray.sumRange(4, 4) << endl;
  numArray.update(3, 8);
  numArray.print();
  cout << numArray.sumRange(0, 4) << endl;
  // cout << numArray.sumRange(0, 0) << endl;
  // numArray.update(2, 6);
  // cout << numArray.sumRange(0, 1) << endl;
  // cout << numArray.sumRange(1, 2) << endl;
  // cout << numArray.sumRange(2, 2) << endl;

  return 0;
}