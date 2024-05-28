#include<bits/stdc++.h>
using namespace std;
class TimeMap {
private:
  unordered_map<string, map<int, string>> timebase_map;
public:

  TimeMap() {
  }

  void set(string key, string value, int timestamp) {
    this->timebase_map[key].insert({ timestamp, value });
  }

  string get(string key, int timestamp) {
    // 找極值method前題是要sort過, 所以用map
    // upper_bound找大於, lower_bound找大於等於
    // 所以upper_bound要往前一個
    auto iterator = timebase_map[key].upper_bound(timestamp);
    if (iterator == timebase_map[key].begin()) {
      return "";
    }
    else {
      return prev(iterator)->second;
    }
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
