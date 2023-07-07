int lengthOfLongestSubstring(string s)
{
    vector<int> mp(127, -1);
    int ans = 0, l = 0, j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] == -1 || mp[s[i]] < j)
        {
            l++;
            mp[s[i]] = i;
        }
        else
        {
            l = i - mp[s[i]];
            j = mp[s[i]] + 1;
            mp[s[i]] = i;
        }
        // cout<<l<<" ";
        ans = max(ans, l);
    }
    return ans;
}