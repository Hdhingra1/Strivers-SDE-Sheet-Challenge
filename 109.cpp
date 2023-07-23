class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string temp = countAndSay(n - 1);
        vector<pair<int, char>> v;
        char it = temp[0];
        int l = 1;
        int i;
        for (i = 1; i < temp.length(); i++)
        {
            if (temp[i] == temp[i - 1])
            {
                l++;
            }
            else
            {
                v.push_back({l, temp[i - 1]});
                l = 1;
            }
        }
        v.push_back({l, temp[i - 1]});
        string ans = "";
        for (auto it : v)
        {
            ans += to_string(it.first);
            ans += it.second;
        }
        return ans;
    }
};