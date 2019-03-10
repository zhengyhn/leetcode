#include <iostream>
#include <vector>

using namespace std;

class NumArray {
  private:
    vector<int> sums;
    vector<int> nums;

    void build(int left, int right, int sumIdx) {
      if (left == right) {
        this->sums[sumIdx] = this->nums[left - 1];
        return;
      }
      int mid = (left + right) / 2;
      build(left, mid, 2 * sumIdx);
      build(mid + 1, right, 2 * sumIdx + 1);
      this->pushUp(sumIdx);
    }

    void pushUp(int sumIdx) {
      this->sums[sumIdx] = this->sums[2 * sumIdx] + this->sums[2 * sumIdx + 1];
    }

    void updateOne(int numIdx, int val, int left, int right, int sumIdx) {
      if (left == right) {
        this->sums[sumIdx] = val;
        return;
      }
      int mid = (left + right) / 2;
      if (mid >= numIdx) {
        this->updateOne(numIdx, val, left, mid, sumIdx * 2);
      } else {
        this->updateOne(numIdx, val, mid + 1, right, sumIdx * 2 + 1);
      }
      this->pushUp(sumIdx);
    }
    int query(int leftBound, int rightBound, int left, int right, int sumIdx) {
      if (leftBound <= left && rightBound >= right) {
        return this->sums[sumIdx];
      }
      int sum = 0;
      int mid = (left + right) / 2;
      if (mid >= leftBound) {
        sum += this->query(leftBound, rightBound, left, mid, 2 * sumIdx);
      }
      if (mid < rightBound) {
        sum += this->query(leftBound, rightBound, mid + 1, right, 2 * sumIdx + 1);
      }
      return sum;
    }
public:
    NumArray(vector<int> nums) {
      this->nums = nums;
      this->sums = vector<int>(nums.size() * 4 + 1);
      if (nums.size() <= 0) {
        return;
      }
      this->build(1, nums.size(), 1);
    }
    
    void update(int i, int val) {
      this->updateOne(i + 1, val, 1, this->nums.size(), 1);
    }
    
    int sumRange(int i, int j) {
       return this->query(i + 1, j + 1, 1, this->nums.size(), 1); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main() {
    vector<int> nums;
    nums = {1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(0, 2);
    cout << numArray.sumRange(0, 0) << endl;
    numArray.update(2, 6);
    cout << numArray.sumRange(0, 1) << endl;
    cout << numArray.sumRange(1, 2) << endl;
    cout << numArray.sumRange(2, 2) << endl;


    return 0;
}