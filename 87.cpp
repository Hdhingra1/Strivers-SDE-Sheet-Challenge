#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() <= curr)
        {
            if (st.top() == (-1))
            {
                break;
            }
            else
            {
                st.pop();
            }
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}