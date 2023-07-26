#include <bits/stdc++.h>

bool solve(vector<vector<int>> &edges, int start, vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[node][i])
            {
                if (color[i] == -1)
                {
                    color[i] = !color[node];
                    q.push(i);
                }
                else if (color[i] == color[node])
                    return false;
            }
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> color(edges.size(), -1);
    for (int i = 0; i < edges.size(); i++)
    {
        if (color[i] == -1)
        {
            if (!solve(edges, i, color))
                return false;
        }
    }
    return true;
}