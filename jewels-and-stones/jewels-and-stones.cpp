#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int numJewelsInStones(string J, string S) {
      unordered_map<char, int> map;
      for (char item: J) {
        map[item] = 1;
      }
      int count = 0;
      for (char item: S) {
        if (map.find(item) != map.end()) {
          ++count;
        }
      }
      return count;
    }
};

int main() {
  Solution sln;
  std::cout << sln.numJewelsInStones("aA", "aAAbbbb") << std::endl;
  std::cout << sln.numJewelsInStones("z", "ZZ") << std::endl;
  std::cout << sln.numJewelsInStones("", "ZZ") << std::endl;
  std::cout << sln.numJewelsInStones("a", "") << std::endl;

  return 0;
}
