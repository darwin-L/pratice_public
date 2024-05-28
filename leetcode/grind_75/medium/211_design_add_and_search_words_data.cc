// 第一反應: 有點類似prefix樹, 但這邊搜尋的主體是模糊查詢,並且限制查詢的字元長度, 所以每一個字元都要有向量
#include<bits/stdc++.h>
using namespace std;
class WordDictionary {
  vector<WordDictionary*> dictionary_vec;
  bool end_of_word;
public:
  WordDictionary() :end_of_word(false) {
    this->dictionary_vec = vector<WordDictionary*>(26, nullptr);
  }

  void addWord(string word) {
    WordDictionary* curr = this;
    for (char c : word) {
      if (curr->dictionary_vec[c - 'a'] == nullptr)  curr->dictionary_vec[c - 'a'] = new WordDictionary();
      curr = curr->dictionary_vec[c - 'a'];
    }
    curr->end_of_word = true;

  }

  bool search(string word) {
    WordDictionary* curr = this;
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == '.') {
        for (auto ele : curr->dictionary_vec) {
          if (ele != nullptr && ele->search(word.substr(i + 1))) return true;
        }
        return false;
      }
      if(curr->dictionary_vec[word[i] - 'a'] == nullptr) return false;
      curr = curr->dictionary_vec[word[i]- 'a'];
    }
    return curr->end_of_word;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */