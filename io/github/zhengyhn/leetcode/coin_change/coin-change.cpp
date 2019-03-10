#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    unordered_map<int, int> map;

    int coinChangeOld(vector<int>& coins, int amount) {
      if (amount == 0) {
        return 0;
      }
      if (coins.size() == 0) {
        return -1;
      }
      map.clear();
      int ret = this->robot(coins, amount);
      return ret == -1 ? -1 : ret;
    }

    int robot(vector<int>& coins, int amount) {
      if (amount == 0) {
        return 0;
      }
      if (amount < 0) {
        return -1;
      }
      if (this->map.find(amount) != map.end()) {
        return this->map[amount];
      }
      int min = 1000;
      for (int i = 0; i < coins.size(); ++i) {
        int temp = robot(coins, amount - coins[i]);
        if (temp >= 0 && temp < min) {
          min = temp;
        }
      }
      if (min == 1000) {
        this->map[amount] = -1;
        return -1;
      }
      this->map[amount] = min + 1;
      return min + 1;
    }

    int coinChange(vector<int>& coins, int amount) {
      if (amount == 0) {
        return 0;
      }
      if (coins.size() == 0) {
        return -1;
      }
      vector<int> cache(amount + 1, -1);
      cache[0] = 0;
      for (int i = 1; i <= amount; ++i) {
        int min = 1000;
        for (int j = 0; j < coins.size(); ++j) {
          if (i - coins[j] < 0) {
            continue;
          }
          if (cache[i - coins[j]] != -1 && cache[i - coins[j]] < min) {
            min = cache[i - coins[j]];
          }
        }
        cache[i] = min == 1000 ? -1 : min + 1;
        // std::cout << cache[i] << std::endl;
      }
      return cache[amount];
    }
};

int main() {
  Solution sln;
  vector<int> coins;
  // coins = {1, 2, 5};
  // std::cout << sln.coinChange(coins, 11) << std::endl;
  // coins = {2};
  // std::cout << sln.coinChange(coins, 3) << std::endl;
  // coins = {2};
  // std::cout << sln.coinChange(coins, 0) << std::endl;
  // coins = {};
  // std::cout << sln.coinChange(coins, 1) << std::endl;
  // std::cout << sln.coinChange(coins, 0) << std::endl;
  // coins = {186,419,83,408};
  // std::cout << sln.coinChange(coins, 6249) << std::endl;
  // coins = {};
  for (int i = 0; i < 9999; ++i) {
    coins.push_back(1);
  }
  coins.push_back(10000);
  std::cout << sln.coinChangeOld(coins, 10000) << std::endl;

  return 0;
}
