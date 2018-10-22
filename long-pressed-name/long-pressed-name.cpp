#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while (i < name.size() || j < typed.size()) {
            // cout << i << " " << j << endl;
            if (name[i] == typed[j]) {
                ++i;
                ++j;
            } else if (i > 0 && name[i - 1] == typed[j]) {
                ++j;
            } else if (name[i] != typed[j]) {
                return false;
            }
        }
        if (i == name.size() && j == typed.size()) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution sln;
    cout << sln.isLongPressedName("alex", "aaleex") << endl;
    cout << sln.isLongPressedName("saeed", "ssaaedd") << endl;
    cout << sln.isLongPressedName("leelee", "lleeelee") << endl;
    cout << sln.isLongPressedName("laiden", "laiden") << endl;
    cout << sln.isLongPressedName("vtkgnn", "vttkgnn") << endl;

    return 0;
}