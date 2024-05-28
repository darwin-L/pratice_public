#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  unordered_map<char, int> letters;
  bool canConstruct(string ransomNote, string magazine) {
    for (auto c : magazine) letters[c]++;

    for (auto c : ransomNote) {
      auto iterator = letters.find(c);
      if (iterator == letters.end() || iterator->second == 0) {
        return false;
      }
      iterator->second--;
    }
  }
};