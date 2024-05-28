// 第一反應: 想像中用O(m+n)空間複雜, 只要在該行發現0就紀錄垂直以及水平, 接著根據這些紀錄修改原始陣列
// 要用O(c)空間複雜度
// 1 1 1 1
// 1 0 1 1
// 1 1 1 1  ->
// 1 1 1 0
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // 跟542 01-matrix有一點像, 可以利用左上右下的方式去搜尋
        // 第一行與 第一列 都是控制項, 不能輕易更動
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};

// * 更長但比較直覺的code
// void setZeroes(vector<vector<int>>& matrix) {
//         bool isZeroCol = false;
//         bool isZeroRow = false;
//         for (int i = 0; i < matrix.size(); i++) { //check the first column
//             if (matrix[i][0] == 0) {
//                 isZeroCol = true;
//                 break;
//             } 
//         }
//         for (int i = 0; i < matrix[0].size(); i++) { //check the first row
//             if (matrix[0][i] == 0) {
//                 isZeroRow = true;
//                 break;
//             } 
//         }
//         for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
//             for (int j = 1; j < matrix[0].size(); j++) 
//                 if (matrix[i][j] == 0) {
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//         }
//         for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
//            for (int j = 1; j < matrix[0].size(); j++) 
//                if (matrix[i][0] == 0 || matrix[0][j] == 0)
//                    matrix[i][j] = 0;
//         }
//         if (isZeroCol) { //handle the first column
//             for (int i = 0; i < matrix.size(); i++) 
//                 matrix[i][0] = 0;
//         }
//         if (isZeroRow) { //handle the first row
//             for (int i = 0; i < matrix[0].size(); i++) 
//                 matrix[0][i] = 0;
//         }