#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int C)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    int i = 0;
    for (auto it : A)
    {
        pq.push({it + B[n - 1], {i, n - 1}});
        i++;
    }
    while (C--)
    {
        auto it = pq.top();
        pq.pop();
        ans.push_back(it.first);
        int x = it.second.first;
        int y = it.second.second;
        if (y != 0)
        {
            pq.push({A[x] + B[y - 1], {x, y - 1}});
        }
    }
    return ans;
}