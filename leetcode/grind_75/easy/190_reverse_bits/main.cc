// 第一反應: 將輸入的字串從頭讀到尾, 轉成10進位, 但這個方法的空間跟時間利用程度不好
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {

    // 每次取一半的位數去做調換
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

    return n;

  }
};