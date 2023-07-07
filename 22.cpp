#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> m;
    int pre_sum = 0;
    int longest = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == 0)
        {
            longest = i + 1;
        }
        else
        {
            if (m.find(pre_sum) != m.end())
            {
                longest = max(longest, i - m[pre_sum]);
            }
            else
            {
                m[pre_sum] = i;
            }
        }
    }
    return longest;
}