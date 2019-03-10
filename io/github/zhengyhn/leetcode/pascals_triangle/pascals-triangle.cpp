/*
 * =====================================================================================
 *
 *       Filename:  pascals-triangle.cpp
 *
 *    Description:  打印帕斯卡三角
 *
 *        Version:  1.0
 *        Created:  08/02/2015 04:44:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRows) {
      vector< vector<int> > result;

      for (int i = 0; i < numRows; ++i) {
        vector<int> row;
        row.push_back(1); 

        for (int j = 1; j < i; ++j) {
          row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
        }
        if (i > 0 ) {
          row.push_back(1);
        }
        result.push_back(row);
      }
      return result;
    }
};

int main() {
  Solution sln;
  vector< vector<int> > result = sln.generate(5);
  
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
}
