#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int numRescueBoats(vector<int>& people, int limit) {
      if (people.size() <= 0) {
        return 0;
      }
      sort(people.begin(), people.end());
      int ret = 0;
      int i = 0;
      int end = people.size() - 1;
      while (i < people.size()) {
        if (i == end) {
          ret += 1;
          ++i;
          end = people.size() - 1;
          continue;
        }
        if (people[i] + people[end] > limit) {
          --end;
        } else {
          ret += 1;
          people.erase(people.begin() + end);
          ++i;
          end = people.size() - 1;
        }
      }

      return ret;
    }
};
int main() {
  Solution sln;
  vector<int> people;
  people = {1, 2};
  cout << sln.numRescueBoats(people, 3) << endl;
  people = {3, 2, 2, 1};
  cout << sln.numRescueBoats(people, 3) << endl;
  people = {3, 5, 3, 4};
  cout << sln.numRescueBoats(people, 5) << endl;
  people = {5, 1, 4, 2};
  cout << sln.numRescueBoats(people, 6) << endl;

  return 0;
}
