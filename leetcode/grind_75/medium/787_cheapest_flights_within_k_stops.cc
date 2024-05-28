// 第一反應: 最短路徑演算法, dp類型
// TODO: 再複習一次所有的演算法差別, 並確認什麼樣的限制導致了這個算法
#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
class Solution
{
public:
    // Dijkstra的變體, 因為有K站的限制所以不用去比較並保存最好的路徑, 直接拿目前剩餘k站所有的可能拿來用
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<pair<int, int>>> cost_pair(n);
        for (const auto &f : flights)
            cost_pair[f[0]].emplace_back(f[1], f[2]);

        priority_queue<ti, vector<ti>, greater<ti>> pq;

        pq.emplace(0, src, K + 1);
        while (!pq.empty())
        {
            auto [cost, u, stops] = pq.top();
            pq.pop();
            if (u == dst)
                return cost;

            if (!stops)
                continue;

            for (auto to : cost_pair[u])
            {
                auto [v, w] = to;
                pq.emplace(cost + w, v, stops - 1);
            }
        }
        return -1;
    }

    /*  In bellman-ford algo calculates the shortest distance from the source
        point to all of the vertices.
        Time complexity of Bellman-Ford is O(VE),
    */
    int findCheapestPrice_bellman_ford(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        /* distance from source to all other nodes */
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Run only K+1 times since we want shortest distance in K hops
        for (int i = 0; i <= K; i++)
        {
            vector<int> tmp(dist);
            for (auto flight : flights)
            {
                if (dist[flight[0]] != INT_MAX)
                {
                    tmp[flight[1]] = min(tmp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }

    // will get TLE
    int findCheapestPrice_Dijkstra(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto flight : flights)
        {
            // flight[0] represent node i, flight[1] represent neighbor node of node i, flight[2] represent cost between node i to neighbor node
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        // it will store [node, cost]
        queue<pair<int, int>> q;
        q.push({src, 0});
        // it will store minimum cost to reach each node
        vector<int> minCost(n, INT_MAX);
        int stops = 0;
        while (!q.empty() && stops <= k)
        {
            int size = q.size();
            while (size--)
            {
                auto [currNode, cost] = q.front();
                q.pop();
                for (auto &[neighbour, price] : adj[currNode])
                {
                    if (price + cost < minCost[neighbour])
                    {
                        minCost[neighbour] = price + cost;
                        q.push({neighbour, minCost[neighbour]});
                    }
                }
            }
            stops++;
        }
        if (minCost[dst] == INT_MAX)
            return -1;
        return minCost[dst];
    }
};