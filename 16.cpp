#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    int c = 0, c1 = 0, e = INT_MIN, e1 = INT_MIN;
    for (auto it : nums)
    {
        if (it == e)
            c++;
        else if (it == e1)
            c1++;
        else if (c == 0)
        {
            c++;
            e = it;
        }
        else if (c1 == 0)
        {
            c1++;
            e1 = it;
        }
        else
        {
            c1--;
            c--;
        }
    }
    c = 0, c1 = 0;
    for (auto it : nums)
    {
        if (it == e)
            c++;
        else if (it == e1)
            c1++;
    }
    vector<int> ans;
    if (c >= n / 3 + 1)
        ans.push_back(e);
    if (c1 >= n / 3 + 1)
        ans.push_back(e1);
    return ans;
}