#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  /**
   *
   * @param n int整型 城市个数n
   * @param nums int整型vector<vector<>> 城市间的车票价钱 n行n列的矩阵
   * @return int整型
   */
  int travel(int n, vector<vector<int>>& nums) {
    // write code here
    int ret = 0x33ffffff;
    vector<int> rest(n);
    for (int i = 0; i < n; ++i) {
      rest[i] = i;
    }
    vector<vector<int>> result;
    vector<int> item;
    int sum = 0;
    perm(rest, item, nums, sum, ret);
    // for (int i = 0; i < result.size(); ++i) {
    //   // for (int k = 0; k < result[i].size(); ++k) {
    //   //   cout << result[i][k] << " ";
    //   // }
    //   // cout << endl;
    //   int sum = 0;
    //   for (int j = 0; j < result[i].size() - 1; ++j) {
    //     sum += nums[result[i][j]][result[i][j + 1]];
    //   }
    //   sum += nums[result[i][result[i].size() - 1]][result[i][0]];
    //   ret = min(ret, sum);
    // }
    return ret;
  }
  void perm(vector<int>& rest, vector<int>& item, vector<vector<int>>& nums,
            int& sum, int& ret) {
    if (rest.size() == 0) {
      ret = min(ret, sum + nums[item.back()][item[0]]);
      // result.push_back(vector<int>(item));
      // item.clear();
      return;
    }
    for (int i = 0; i < rest.size(); ++i) {
      int value = rest[i];
      sum += item.size() > 0 ? nums[item.back()][value] : 0;
      item.push_back(value);
      rest.erase(rest.begin() + i);
      perm(rest, item, nums, sum, ret);
      item.pop_back();
      sum -= item.size() > 0 ? nums[item.back()][value] : 0;
      rest.insert(rest.begin() + i, value);
    }
  }
};

int main() {
  Solution sln;
  vector<vector<int>> nums = {
      {0, 2, 6, 5}, {2, 0, 4, 4}, {6, 4, 0, 2}, {5, 4, 2, 0}};
  cout << sln.travel(4, nums) << endl;
}