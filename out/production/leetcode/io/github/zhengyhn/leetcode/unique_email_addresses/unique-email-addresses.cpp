#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
      set<string> result;
      for (string email: emails) {
        string temp;
        for (int i = 0; i < email.size(); ++i) {
          if (email[i] == '.') {
            continue;
          } else if (email[i] == '+') {
            while (email[i] != '@') {
              ++i;
            }
            --i;
          } else if (email[i] == '@') {
            temp.append(email.substr(i, email.size() - i));
            break;
          } else {
            temp.push_back(email[i]);
          }
        }
        result.insert(temp);
      }
      return result.size();
    }
};

int main() {
    Solution sln;
    vector<string> emails = {
      "test.email+alex@leetcode.com",
      "test.e.mail+bob.cathy@leetcode.com",
      "testemail+david@lee.tcode.com"
    };
    cout << sln.numUniqueEmails(emails) << endl;

    return 0;
}