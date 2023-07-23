class Solution
{
public:
    vector<vector<string>> ans;
    int dp[16][16];
    void solve(string &s, vector<string> &a, int start)
    {
        if (start >= s.size())
        {
            ans.push_back(a);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            // string tmp = s.substr(start,s.size()-(i-start+1));
            string tmp = s.substr(start, i - start + 1);
            if (check(tmp))
            {
                a.push_back(tmp);
                solve(s, a, i + 1);
                a.pop_back();
            }
        }
    }
    bool check(string &s)
    {
        int n = s.size() - 1;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[n - i])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> a;
        solve(s, a, 0);
        return ans;
    }
};