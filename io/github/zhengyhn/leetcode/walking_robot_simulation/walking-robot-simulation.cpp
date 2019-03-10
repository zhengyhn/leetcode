#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool sort_func(vector<int>& a, vector<int>& b) {
  if (a[0] == b[0]) {
    return abs(a[1]) < abs(b[1]);
  }
  return abs(a[0]) < abs(b[0]);
}
class Solution {
  public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
      sort(obstacles.begin(), obstacles.end(), sort_func);
      int endX = 0;
      int endY = 0;
      int dir = 0;
      for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == -1 || commands[i] == -2) {
          dir = changeDir(dir, commands[i]);
          continue;
        }
        int tempX = endX;
        int tempY = endY;
        if (dir == 0) {
          tempY += commands[i];
        } else if (dir == 1) {
          tempX += commands[i];
        } else if (dir == 2) {
          tempY -= commands[i];
        } else {
          tempX -= commands[i];
        }
        if (tempX != endX) {
          int temp = tempX;
          for (int k = 0; k < obstacles.size(); ++k) {
            if (endY == obstacles[k][1]) {
              if (tempX <= obstacles[k][0] && endX > obstacles[k][0]) {
                temp = obstacles[k][0] + 1;
                break;
              }
              if (tempX >= obstacles[k][0] && endX < obstacles[k][0]) {
                temp = obstacles[k][0] - 1;
                break;
              }
            }
          }
          tempX = temp;
        }
        if (tempY != endY) {
          int temp = tempY;
          for (int k = 0; k < obstacles.size(); ++k) {
            if (endX == obstacles[k][0]) {
              if (tempY <= obstacles[k][1] && endY > obstacles[k][1]) {
                temp = obstacles[k][1] + 1;
                break;
              }
              if (tempY >= obstacles[k][1] && endY < obstacles[k][1]) {
                temp = obstacles[k][1] - 1;
                break;
              }
            }
          }
          tempY = temp;
        }
        endX = tempX;
        endY = tempY;
        // cout << "cur: " << endX << " " << endY << endl;
      }
      return endX * endX + endY * endY;
    }

    int changeDir(int dir, int command) {
      if (command == -1) {
        dir = (dir + 1) % 4;
      } else {
        dir = (dir - 1 + 4) % 4;
      }
      return dir;
    }
};

int main() {
  Solution sln;
  vector<int> commands;
  vector<vector<int>> obstacles;
  commands = {4,-1,3};
  obstacles = {};
  cout << sln.robotSim(commands, obstacles) << endl;
  commands = {4,-1,4,-2,4};
  obstacles = {{2, 4}};
  cout << sln.robotSim(commands, obstacles) << endl;
  commands = {7,-2,-2,7,5};
  obstacles = {{-3,2},{-2,1},{0,1},{-2,4},{-1,0},{-2,-3},{0,-3},{4,4},{-3,3},{2,2}};
  cout << sln.robotSim(commands, obstacles) << endl;
  commands = {4, -1, 4, -1, 4, -1, 4};
  obstacles = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  cout << sln.robotSim(commands, obstacles) << endl;

  return 0;
}
