class Solution
{
public:
    int myAtoi(string s)
    {
        int flag = 0;
        int mx = pow(2, 31) - 1;
        long long ans = 0;
        int c = 1;
        int k = 0;
        for (auto it : s)
        {
            if (k == 1 && !(it <= '9' && it >= '0'))
                break;
            if (it == '-' || it == '+')
            {
                k = 1;
                if (c >= 2)
                    return 0;
                c++;
                if (it == '-')
                    flag = 1;
                continue;
            }
            if (it <= '9' && it >= '0')
            {
                k = 1;
                c++;
                ans = ans * 10 + (it - '0');
                // c*=10;
            }
            else if (it == ' ' || it == '+')
                continue;
            else
            {
                break;
            }
            if (flag == 1 && ans - 1 >= mx)
                return -1 * mx - 1;
            if (flag == 0 && ans >= mx)
                return mx;
        }

        return flag == 1 ? -1 * ans : ans;
    }
};