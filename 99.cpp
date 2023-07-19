class Solution
{
public:
    string reverseWords(string s)
    {
        string ans;
        string temp;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && temp.length() > 0)
            {
                if (ans.length() != 0)
                    ans += " ";
                for (int j = temp.length() - 1; j >= 0; j--)
                {
                    ans += temp[j];
                }
                temp = "";
            }
            else if (s[i] == ' ')
            {
            }
            else
            {
                temp += s[i];
            }
        }
        if (temp.length() && ans.length())
            ans += ' ';
        for (int j = temp.length() - 1; j >= 0; j--)
        {
            ans += temp[j];
        }
        return ans;
    }
};