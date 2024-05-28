// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include<vector>
using namespace std;

class Solution {
public:
  int firstBadVersion(int n) {
    int start = 1;
    int end = n;
    // constraints always has bad versions
    while (start < end)
    {
      // https://stackoverflow.com/questions/38688028/why-prefer-start-end-start-2-over-start-end-2-when-calculating-the
      // 另外就是如果直接使用end/2 也會有跳不出迴圈的問題. e.g. 3/2 -> 1 
      int middle = start + ((end - start) / 2);
      if (!isBadVersion(middle))
      {
        start = middle + 1;
      }
      else {
        end = middle;
      }
    }
    return start;
  }
  bool isBadVersion(int version) {}
};