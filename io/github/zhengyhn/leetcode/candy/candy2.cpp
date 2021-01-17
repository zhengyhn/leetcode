#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    vector<int> left(ratings.size(), 1);
    vector<int> right(ratings.size(), 1);
    int ret = 0;
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        left[i] = left[i - 1] + 1;
      }
    }
    ret += left[ratings.size() - 1];
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        right[i] = right[i + 1] + 1;
      }
      ret += max(right[i], left[i]);
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<int> ratings;
  ratings = {25, 94, 89, 54, 26, 54, 54, 99, 64};
  cout << sln.candy(ratings) << endl;
}