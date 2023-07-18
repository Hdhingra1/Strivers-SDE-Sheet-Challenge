#include <bits/stdc++.h>
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> ans;
    priority_queue<int> pq;
    for (auto it : q)
    {
        if (it[0] == 0)
        {
            pq.push(-1 * it[1]);
        }
        else
        {
            ans.push_back(-1 * pq.top());
            pq.pop();
        }
    }
    return ans;
}
