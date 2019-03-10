#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      if (prices.size() <= 1) {
        return 0;
      }
      int lastBuy = 0;
      int totalProfit = 0;
      int i = 1;
      for (; i < prices.size(); ++i) {
        if (prices[i] < prices[i - 1]) {
          totalProfit += prices[i - 1] - prices[lastBuy];
          lastBuy = i;
        }
      }
      if (lastBuy < i - 1) {
        totalProfit += prices[i - 1] - prices[lastBuy];
      }
      return totalProfit;
    }
};

int main() {
  Solution sln;
  // vector<int> prices = {7, 1, 5, 3, 6, 4};
  // vector<int> prices = {1, 2, 3, 4};
  vector<int> prices = {4, 1};
  std::cout << sln.maxProfit(prices) << std::endl;

  return 0;
}
