// 第一反應: 用空間換時間 儲存每一次put或read之後, 下次put如果溢出時需要被替換的值(因為一次只會put一個值)
// 因為要直接處理排序問題(抓最小), 所以用list做
// The functions get and put must each run in O(1) average time complexity.
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
private:
  size_t m_capacity;
  // map裡面裝的是list的元素指標, 在put時更新list順序要先拿list更新之後再放到map裡面
  unordered_map<int, list<pair<int, int>>::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
  list<pair<int, int>> m_list;
  int remove_key;
public:
  LRUCache(int capacity) :m_capacity(capacity) {

  }

  int get(int key) {
    auto found_iter = m_map.find(key);
    if (found_iter == m_map.end()) return -1;

    // 把這次使用的元素移到list的頭
    m_list.splice(m_list.begin(), m_list, found_iter->second);
    return found_iter->second->second;
  }

  void put(int key, int value) {
    auto found_iter = m_map.find(key);
    if (found_iter != m_map.end())
    {
      m_list.splice(m_list.begin(), m_list, found_iter->second);
      found_iter->second->second = value;
      return;
    }

    if (m_map.size() == m_capacity)
    {
      // 抓最後一個
      int key_to_del = m_list.back().first;
      m_list.pop_back();            
      m_map.erase(key_to_del); 
    }

    m_list.push_front(make_pair(key, value));
    m_map[key] = m_list.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */