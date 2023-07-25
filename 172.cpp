#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp;
    dp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int it = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (it == dp.size())
        {
            dp.push_back(arr[i]);
        }
        else
        {
            dp[it] = arr[i];
        }
    }
    return dp.size();
}