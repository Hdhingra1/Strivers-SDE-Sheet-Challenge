#include <bits/stdc++.h>
long long check(vector<int> &time, long long mid)
{
    long long ans = 0, s = 0;
    for (int i = 0; i < time.size(); i++)
    {
        s += time[i];
        if (s > mid)
        {
            ans++;
            s = time[i];
        }
    }
    return ans + 1;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    long long h = 0, l = 0;
    for (auto it : time)
    {
        h += it;
        l = max(l, (long long)it);
    }
    while (l <= h)
    {
        long long mid = l + (h - l) / 2;
        if (check(time, mid) <= n)
        {
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return l;
}