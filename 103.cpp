class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string temp = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int idx = 0;
            string s = "";
            while (idx < temp.size() && idx < strs[i].size())
            {
                if (temp[idx] != strs[i][idx])
                    break;
                s += temp[idx];
                idx++;
            }
            temp = s;
        }
        return temp;
    }
};