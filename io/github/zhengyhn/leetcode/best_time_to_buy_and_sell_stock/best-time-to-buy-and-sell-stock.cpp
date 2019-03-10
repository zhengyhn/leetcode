#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int maxProfitOld(vector<int>& prices) {
      if (prices.size() <= 0) {
        return 0;
      }
      int max = 0;
      for (int i = 0; i < prices.size() - 1; ++i) {
        for (int j = i + 1; j < prices.size(); ++j) {
          int value = prices[j] - prices[i];
          if (value > max) {
            max = value;
          }
        }
      }
      return max;
    }
    int maxProfit(vector<int>& prices) {
      int min = 0xffff;
      int max = 0;
      int ret = 0;
      for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] < min) {
          min = prices[i];
          max = prices[i];
        } else if (prices[i] > max) {
          max = prices[i];
        }
        if (max - min > ret) {
          ret = max - min;
        }
      }
      return ret;
    }
    int maxProfit2(vector<int>& prices) {
      int max = 0;
      int maxSoFar = 0;
      for (int i = 1; i < prices.size(); ++i) {
        max += prices[i] - prices[i - 1];
        max = max > 0 ? max : 0; 
        maxSoFar = max > maxSoFar ? max : maxSoFar;
      }
      return maxSoFar;
    }
};

int main() {
  Solution sln;
  vector<int> prices;
  prices = {7, 1, 5, 3, 6, 4};
  std::cout << sln.maxProfit2(prices) << std::endl;
  prices = {7, 6, 4, 3, 1};
  std::cout << sln.maxProfit2(prices) << std::endl;
  prices = {};
  std::cout << sln.maxProfit2(prices) << std::endl;

  return 0;
}
