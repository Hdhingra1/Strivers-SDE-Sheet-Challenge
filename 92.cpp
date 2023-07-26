#include <bits/stdc++.h>

vector<int> nextSmaller(vector<int> &a, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && a[st.top()] >= a[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int> &a, int n)
{
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && a[st.top()] >= a[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangle(vector<int> &heights)
{
    // Write your code here.
    int n = heights.size();
    vector<int> next(n);
    next = nextSmaller(heights, n);
    vector<int> prev(n);
    prev = prevSmaller(heights, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}