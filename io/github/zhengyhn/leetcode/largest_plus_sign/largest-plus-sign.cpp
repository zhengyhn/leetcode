#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
      vector<vector<int>> matrix(N, vector<int>(N));
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          matrix[i][j] = 1;
        }
      }
      for (int i = 0; i < mines.size(); ++i) {
        matrix[mines[i][0]][mines[i][1]] = 0;
      }
      int order = N == 1 ? 1 : (N + 1) / 2;
      while (order > 0) {
        vector<int> first = {N / 2, N / 2};
        queue<vector<int>> queue;
        queue.push(first);
        while (!queue.empty()) {
          vector<int> point = queue.front();
          queue.pop();
          int i = point[0], j = point[1];
          if (matrix[i][j] == -1 || matrix[i][j] == 2) {
            continue;
          }
          bool isValid = this->isValid(matrix, i, j, order);
          if (isValid) {
            return order;
          } else if (matrix[i][j] == 1) {
            matrix[i][j] = 2;
          } else if (matrix[i][j] == 0) {
            matrix[i][j] = -1;
          }
          for (int k = 1; k <= order; ++k) {
            vector<int> temp;
            if (j - k >= 0) {
              temp = {i, j - k};
              queue.push(temp);
            }
            if (j + k < N) {
              temp = {i, j + k};
              queue.push(temp);
            }
            if (i - k >= 0) {
              temp = {i - k, j};
              queue.push(temp);
            }
            if (i + k < N) {
              temp = {i + k, j};
              queue.push(temp);
            }
            if (i - k >= 0 && j - k >= 0) {
              temp = {i - k, j - k};
              queue.push(temp);
            }
            if (i - k >= 0 && j + k < N) {
              temp = {i - k, j + k};
              queue.push(temp);
            }
            if (i + k < N && j - k >= 0) {
              temp = {i + k, j - k};
              queue.push(temp);
            }
            if (i + k < N && j + k < N) {
              temp = {i + k, j + k};
              queue.push(temp);
            }
          }
        }
        --order;
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < N; ++j) {
            if (matrix[i][j] == -1) {
              matrix[i][j] = 0;
            }
            if (matrix[i][j] == 2) {
              matrix[i][j] = 1;
            }
          }
        }
      }
      return order;
    }

    bool isValid(vector<vector<int>>& matrix, int i, int j, int order) {
      if (order == 1) {
        return matrix[i][j] > 0;
      }
      for (int k = 1; k < order; ++k) {
        if (!(
            j - k >= 0 &&
            matrix[i][j - k] > 0 &&
            j + k < matrix.size() &&
            matrix[i][j + k] > 0 &&
            i - k >= 0 &&
            matrix[i - k][j] > 0 &&
            i + k < matrix.size() &&
            matrix[i + k][j] > 0 
           )) {
          return false;
        }
      }
      return true;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> mines = {{4, 2}};
  std::cout << sln.orderOfLargestPlusSign(5, mines) << std::endl;
  mines = {}; 
  std::cout << sln.orderOfLargestPlusSign(2, mines) << std::endl;
  mines = {{0, 0}}; 
  std::cout << sln.orderOfLargestPlusSign(1, mines) << std::endl;
  mines = {{0, 1}, {1, 0}, {1, 1}};
  std::cout << sln.orderOfLargestPlusSign(2, mines) << std::endl;

  return 0;
}
