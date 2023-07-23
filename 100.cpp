class Solution
{
public:
    int fun(int i, int j, string &s)
    {
        int ans = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            ans++;
            i--;
            j++;
        }
        return 2 * ans;
    }
    string longestPalindrome(string s)
    {
        int st, j, length = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int c = fun(i, i, s) - 1;
            // cout<<c<<" ";
            if (c > length)
            {
                length = c;
                st = i - length / 2;
                // j = i + length;
            }
        }
        for (int i = 0; i < s.length() - 1; i++)
        {
            int c = fun(i, i + 1, s);
            if (c > length)
            {
                length = c;
                st = i - length / 2 + 1;
                // j = i + length;
            }
        }

        cout << length << " " << st;
        return s.substr(st, length);
        // return s;
    }
};