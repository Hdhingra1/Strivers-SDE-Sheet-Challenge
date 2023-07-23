class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> s;
        s.insert({0, S});
        vector<int> dis(V, INT_MAX);
        dis[S] = 0;
        while (!s.empty())
        {
            auto it = *s.begin();
            s.erase(s.begin());
            for (auto i : adj[it.second])
            {
                if (it.first + i[1] < dis[i[0]])
                {
                    if (dis[i[0] != INT_MAX])
                    {
                        s.erase({dis[i[0]], i[0]});
                    }
                    dis[i[0]] = it.first + i[1];
                    s.insert({dis[i[0]], i[0]});
                }
            }
        }
        return dis;
    }
};