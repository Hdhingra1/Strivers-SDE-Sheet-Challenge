class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int findp(int parent[], int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findp(parent, parent[u]);
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int parent[V];
        int size[V];
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            size[i] = 1;
            for (auto k : adj[i])
            {
                edges.push_back({k[1], k[0], i});
            }
        }
        sort(edges.begin(), edges.end());
        int ans = 0;
        for (auto i : edges)
        {
            int u = i[1];
            int v = i[2];
            u = findp(parent, u);
            v = findp(parent, v);
            if (u == v)
                continue;
            ans += i[0];
            if (size[v] > size[u])
            {
                parent[u] = v;
                size[v] += size[u];
            }
            else
            {
                parent[v] = u;
                size[u] += size[v];
            }
        }
        return ans;
    }
};