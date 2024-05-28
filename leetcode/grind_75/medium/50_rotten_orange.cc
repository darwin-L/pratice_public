#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution
{
  private:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    // 從每一個rotten point的四周開始走訪, 每走過一個點進行flag標記並存到queue裡面
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited = grid;
        queue<pair<int, int>> queue_of_unvisited;

        int count_of_fresh_orange = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] == 2)
                {
                    queue_of_unvisited.push({i, j});
                }
                if (visited[i][j] == 1)
                {
                    count_of_fresh_orange++;
                }
            }
        }

        if (count_of_fresh_orange == 0)
            return 0;
        if (queue_of_unvisited.empty())
            return -1;

        int minutes = -1;
        
        while (!queue_of_unvisited.empty())
        {
            int current_size = queue_of_unvisited.size();
            while (current_size)
            {
                auto [current_x, current_y] = queue_of_unvisited.front();
                queue_of_unvisited.pop();
                for (auto [dir_x, dir_y] : this->directions)
                {
                    int i = current_x + dir_x;
                    int j = current_y + dir_y;
                    // 確認邊界 與 確認該點可往外延伸
                    if (i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == 1)
                    {
                        visited[i][j] = 2;
                        count_of_fresh_orange--;
                        queue_of_unvisited.push({i, j});
                    }
                }

                current_size--;
            }
            minutes++;
        }
        if (count_of_fresh_orange == 0)
            return minutes;
        return -1;
    }
};