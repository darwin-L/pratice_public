//https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/

// Given two integers tomatoSlices and cheeseSlices. The ingredients of different burgers are as follows:

//     Jumbo Burger: 4 tomato slices and 1 cheese slice.
//     Small Burger: 2 Tomato slices and 1 cheese slice.

// Return [total_jumbo, total_small] so that the number of remaining tomatoSlices equal to 0 and the number of remaining cheeseSlices equal to 0. If it is not possible to make the remaining tomatoSlices and cheeseSlices equal to 0 return [].



// Example 1:

// Input: tomatoSlices = 16, cheeseSlices = 7
// Output: [1,6]
// Explantion: To make one jumbo burger and 6 small burgers we need 4*1 + 2*6 = 16 tomato and 1 + 6 = 7 cheese.
// There will be no remaining ingredients.

// Example 2:

// Input: tomatoSlices = 17, cheeseSlices = 4
// Output: []
// Explantion: There will be no way to use all ingredients to make small and jumbo burgers.

// Example 3:

// Input: tomatoSlices = 4, cheeseSlices = 17
// Output: []
// Explantion: Making 1 jumbo burger there will be 16 cheese remaining and making 2 small burgers there will be 15 cheese remaining.



// Constraints:

//     0 <= tomatoSlices, cheeseSlices <= 10^7
#include<vector>
using namespace std;
class Solution {
// 另一種寫法可以用逼近的, 從參數小的下手, 逐漸逼近解答, 但是時間複雜度沒有那麼好並且無解的情形判斷比較複雜
// https://www.parenting.com.tw/article/5093334
public:
  vector<int> numOfBurgers(int t, int c) {
    // 矩陣是否有解的檢查, 這邊是因為題目設計剛好都是整數, 不然如果該條件太難下或是步長非整數, 使用逼近法會比較好寫
    if (t % 2 == 0 && c * 2 <= t && t <= c * 4)
      // 雞兔同龍問題, 用二維矩陣消去求解即可
      return { t / 2 - c, c * 2 - t / 2 };
    return {};
  }
};