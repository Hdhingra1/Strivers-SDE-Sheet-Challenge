#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;
    ans.push_back(arr[0]);
    if (arr.size() == 1)
    {
        return ans;
    }
    ans.push_back((arr[0] + arr[1]) / 2);
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    mx.push(min(arr[0], arr[1]));
    mn.push(max(arr[0], arr[1]));
    for (int i = 2; i < arr.size(); i++)
    {
        int mxs = mx.size(), mns = mn.size();
        if (mxs == mns)
        {
            if (arr[i] < mn.top())
            {
                mx.push(arr[i]);
                ans.push_back(mx.top());
            }
            else
            {
                mn.push(arr[i]);
                ans.push_back(mn.top());
            }
            continue;
        }
        if (mxs > mns)
        {
            if (arr[i] < mn.top() && arr[i] < mx.top())
            {
                mn.push(mx.top());
                mx.pop();
                mx.push(arr[i]);
            }
            else
            {
                mn.push(arr[i]);
            }
            ans.push_back((mx.top() + mn.top()) / 2);
            continue;
        }
        if (mns > mxs)
        {
            if (arr[i] < mn.top())
            {
                mx.push(arr[i]);
            }
            else
            {
                mx.push(mn.top());
                mn.pop();
                mn.push(arr[i]);
            }
            ans.push_back((mx.top() + mn.top()) / 2);
            continue;
        }
    }
    return ans;
    // Write your code here
}
