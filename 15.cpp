#include <bits/stdc++.h>

int findMajorityElement(int nums[], int n)
{
    // Write your code here.
    if (n == 1)
        return nums[0];
    int c = 0, e = 1e5 + 1;
    for (int i = 0; i < n; i++)
    {
        int it = nums[i];
        if (c == 0)
        {
            e = it;
            c++;
        }
        else if (it == e)
            c++;
        else
            c--;
    }
    c = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == e)
            c++;
    }
    // cout<<c<<endl;
    if (n % 2 == 1)
        return c >= (n + 1) / 2 ? e : -1;
    return c > (n + 1) / 2 ? e : -1;
}