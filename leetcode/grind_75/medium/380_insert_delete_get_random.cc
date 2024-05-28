// 第一反應: 正常的get 直接從map裡面拿資料就好 O(1)時間, 但因為每次查都要random, 
// 所以主要是透過一個陣列去給它隨機取
// 不能直接拿unordered_map做, 因為主鍵是val, 用位置做主鍵的話insert, remove的時間會變成O(n)
// 題目要求 "所有"操作都是O(1)時間, 不能直接拿vector做到底, 因為這樣remove的成本可能會是O(n), 查詢時間O(n)
// 也不能拿set做 因為insert, remove, find會是O(ln n)
#include <bits/stdc++.h>
using namespace std;
class RandomizedSet
{
private:
    // 用unordered_map的空間去減少vector的操作時間
    vector<int> nums;
    unordered_map<int, int> m;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (m.find(val) != m.end())
            return false;
        nums.emplace_back(val);
        // val是唯一的當key, 用size當成值, 在remove的時候直接拿值定位val
        m[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (m.find(val) == m.end())
            return false;

        // 把目標值換到陣列的最後一個然後替換, map同步更新該值的位置 這樣每個操作都是O(1)時間
        int last_element = nums.back();
        m[last_element] = m[val];
        nums[m[val]] = last_element;
        nums.pop_back();
        m.erase(val);

        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */