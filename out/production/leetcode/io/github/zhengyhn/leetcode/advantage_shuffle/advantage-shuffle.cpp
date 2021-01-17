#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Solution {
  public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
      srand(time(NULL));
      float temperature = 1000000.0;
      float cool = 0.99;
      int best_adavatage = A.size();
      vector<int> best = A;

      while (temperature > 0.001) {
        vector<int> current = best;

        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(current.begin(), current.end(), std::default_random_engine(seed));
        // int left = rand() % current.size();
        // int right = rand() % current.size();
        // int temp = current[left];
        // current[left] = current[right];
        // current[right] = temp;
        int adavantage = 0;
        for (int i = 0; i < current.size(); ++i) {
          if (current[i] > B[i]) {
            adavantage += 1;
          }
        }
        adavantage = current.size() - adavantage;
        std::cout << adavantage << " " << best_adavatage << " " << rand() / double(RAND_MAX) << " " << exp(-(adavantage - best_adavatage + 1.0) / temperature) << std::endl;
        if (adavantage < best_adavatage || (rand() / double(RAND_MAX) < exp(-(adavantage - best_adavatage + 1.0) / temperature))) {
          best = current;
          best_adavatage = adavantage;
        }
        temperature *= cool;
      }
      return best;
    }
};

int main() {
  Solution sln;
  // vector<int> A = {2,7,11,15};
  // vector<int> B = {1,10,4,11};
  // vector<int> A = {12,24,8,32};
  // vector<int> B = {13,25,32,11};
  // vector<int> A = {2,5,4,1,8};
  // vector<int> B = {4,1,5,8,2};
  vector<int> A = {11,18,7,8,3,17,12,16,0,13};
  vector<int> B = {18,16,3,9,0,11,13,8,7,17};
  vector<int> ret = sln.advantageCount(A, B);
  for (int item: ret) {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  return 0;
}
