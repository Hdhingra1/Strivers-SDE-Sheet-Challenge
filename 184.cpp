#include <bits/stdc++.h>
int dp[104];
bool isPalindrome(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
int palindromePartitioning(string str)
{
    int n = str.size();
    memset(dp, 0, sizeof(dp));

    for (int i = n - 1; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int k = i; k < n; k++)
            if (isPalindrome(str.substr(i, k - i + 1)))
                mini = min(mini, 1 + dp[k + 1]);

        dp[i] = mini;
    }

    return dp[0] - 1;
}