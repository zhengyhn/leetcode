#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int distributeCandies(vector<int>& candies) {
    int sisterCount = 0;
    unordered_set<int> sisterSet;
    int brotherCount = 0;

    for (int i = 0; i < candies.size(); ++i) {
      if (sisterSet.find(candies[i]) != sisterSet.end()) {
        ++brotherCount;
      } else {
        sisterSet.insert(candies[i]);
        ++sisterCount;
      }
    }
    if (brotherCount < candies.size() / 2) {
      sisterCount -= candies.size() / 2 - brotherCount;
    }
    return sisterCount;
  }
};

int main() {
  Solution sln;
  // vector<int> candies = {1,1,2,2,3,3};
  // vector<int> candies = {1,1,2,3};
  vector<int> candies = {100000,0,100000,0,100000,0,100000,0,100000,0,100000,0};
  std::cout << sln.distributeCandies(candies) << std::endl;

  return 0;
}
