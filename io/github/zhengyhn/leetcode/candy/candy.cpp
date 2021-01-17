#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    ratings.push_back(ratings[ratings.size() - 1]);
    int ret = 0;
    int next = 1;
    int last = 1;
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] == ratings[i - 1]) {
        ret += next;
        next = 1;
      } else if (ratings[i] < ratings[i - 1]) {
        int k = i;
        while (k < ratings.size() && ratings[k] < ratings[k - 1]) {
          k++;
        }
        ret += (1 + k - i + 1) * (k - i + 1) / 2;
        if (i >= 2 && ratings[i - 2] > ratings[i - 1] && (k - i + 1) >= last) {
          ret += k - i + 1 + 1 - last;
        }
        i = k;
        if (ratings[i] == ratings[i - 1]) {
          next = 1;
        } else {
          next = 2;
        }
      } else if (ratings[i] > ratings[i - 1]) {
        int k = i;
        while (k < ratings.size() && ratings[k] > ratings[k - 1]) {
          k++;
        }
        ret += (next + k - i + next) * (k - i + 1) / 2;
        last = k - i + next;
        i = k;
        next = 1;
      }
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