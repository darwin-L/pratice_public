#include <bits/stdc++.h>
#include <queue>
using namespace std;
vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int island_count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == 0)
                {
                    island_count++;
                    dfs(grid, visited, n, m, i, j);
                }
            }
        }
        return island_count;
    }
    // 不用回傳數值因為交給上一層去數
    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int n, int m, int current_row, int current_col)
    {
        // 邊界檢查
        if (current_row < 0 || current_row >= n || current_col < 0 || current_col >= m || visited[current_row][current_col] == 1)
        {
            return;
        }
        visited[current_row][current_col] = 1;
        for (auto [dir_x, dir_y] : directions)
        {
            int nRow = current_row + dir_x;
            int nCol = current_col + dir_y;
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && visited[nRow][nCol] == 0)
            {
                dfs(grid, visited, n, m, nRow, nCol);
            }
        }

    }
};