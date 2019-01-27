#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Value {
  string val;
  int timestamp;
  Value(string val, int timestamp) : val(val), timestamp(timestamp) {}
};
class TimeMap {
 private:
  unordered_map<string, vector<Value>> map;

 public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    if (map.find(key) == map.end()) {
      Value item(value, timestamp);
      vector<Value> list = {item};
      map[key] = list;
    } else {
      int i = this->binSearch(key, timestamp);
      // cout << key << " " << timestamp << " " <<  i << endl;
      Value item(value, timestamp);
      map[key].insert(map[key].begin() + i + 1, item);
    }
  }

  string get(string key, int timestamp) {
    if (map.find(key) == map.end()) {
      return "";
    } else {
      int i = this->binSearch(key, timestamp);
      // cout << i << endl;
      return i == -1 ? "" : map[key][i].val;
    }
  }
  int binSearch(string key, int target) {
    int low = 0;
    int high = map[key].size() - 1;
    int ret = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (map[key][mid].timestamp < target) {
        ret = mid;
        low = mid + 1;
      } else if (map[key][mid].timestamp > target) {
        high = mid - 1;
      } else {
        return mid;
      }
    }
    return ret;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
  TimeMap map;
  cout << map.get("aa", 1) << endl;
  map.set("aa", "a", 5);
  map.set("aa", "b", 50);
  cout << map.get("aa", 8) << endl;
  cout << map.get("aa", 88) << endl;

  return 0;
}