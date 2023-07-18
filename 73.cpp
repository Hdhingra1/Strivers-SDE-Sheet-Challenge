#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &a, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < a.size(); i++)
    {
        pq.push({a[i][0], {i, 0}});
    }
    vector<int> ans;
    while (!pq.empty())
    {
        int t = pq.top().first;
        int idx = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        ans.push_back(t);
        if (a[idx].size() > j + 1)
        {
            pq.push({a[idx][j + 1], {idx, j + 1}});
        }
    }
    return ans;
}
