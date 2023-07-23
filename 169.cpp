class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        // vis[0]=1;
        pq.push({0, 0});
        int ans = 0;
        // V--;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            if (vis[it.second] == 1)
                continue;
            vis[it.second] = 1;
            ans += it.first;
            V--;
            if (V == 0)
                return ans;
            for (auto u : adj[it.second])
            {
                if (vis[u[0]] == 0)
                {
                    pq.push({u[1], u[0]});
                }
            }
        }
        return ans;
    }
};