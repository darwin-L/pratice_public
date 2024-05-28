// 第一反應: 兩個for迴圈把所有可能全部列出來
// 要有三個迴圈才能做, 相較於遞迴可以比較難以閱讀但好理解, TODO: 寫出來
// 直接用遞迴把所有元素的交換順序寫好
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    recursive(nums, 0, ans, 0);
    return ans;
  }

  void recursive(vector<int>& nums, int left, vector<vector<int>>& ans, int i) {
    if (left > nums.size() - 1) {
      ans.push_back(nums);
      return;
    }

    //right = left 可以讓結果下一層的迴圈hold住結果, 再執行迴圈
    // 這個操作在三個迴圈的版本就是控制第二層迴圈的
    for (int right = left; right < nums.size(); right++) {
      cout << "left: " << left << "right: " << right << " " << endl;
      cout << endl;
      // performance condition
      if (left != right) {
        swap(nums[left], nums[right]);
      }
      // 遞迴開始, 先走最左邊的排列 ()代表重複的排序
      // ABC -> (ABC)-> (ABC)-> ACB 
      // (ABC) -> BAC -> (BAC) -> BCA
      // (ABC) -> CBA -> (CBA) -> CAB
      recursive(nums, left + 1, ans, right);
      // 完成一次子遞迴, 復原成原本的nums
      swap(nums[left], nums[right]);
    }
  }
};

// TODO: 三個迴圈版本
// public List<List<Integer>> permute(int[] num) {
// 	LinkedList<List<Integer>> res = new LinkedList<List<Integer>>();
// 	res.add(new LinkedList<Integer>());
// 	for (int n : num) {
// 		int size = res.size();
// 		while (size > 0) {
// 			List<Integer> r = res.pollFirst();
// 			for (int i = 0; i <= r.size(); i++) {
// 				List<Integer> temp = new LinkedList<Integer>(r);
// 				temp.add(i, n);
// 				res.add(temp);
// 			}
// 			size--;
// 		}
// 	}
// 	return res;
// }

// TODO: 製表版本, 用used表來減少三個迴圈數量