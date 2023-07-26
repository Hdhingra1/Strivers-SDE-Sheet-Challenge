bool iscycle(int node, vector<vector<int>> &adj, int parent, vector<int> &vis)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            if (iscycle(child, adj, node, vis))
                return true;
        }
        else if (child != parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && iscycle(i, adj, -1, vis))
            return "Yes";
    }
    return "No";
}