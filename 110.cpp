class Solution
{
public:
    int compareVersion(string v1, string v2)
    {
        int c2 = 0;
        int c = 0;
        while (c < v1.length() || c2 < v2.length())
        {
            int vr1 = 0;
            int vr2 = 0;
            while (c < v1.length() && v1[c] != '.')
            {
                vr1 = vr1 * 10 + (v1[c] - '0');
                c++;
            }
            while (c2 < v2.length() && v2[c2] != '.')
            {
                vr2 = vr2 * 10 + (v2[c2] - '0');
                c2++;
            }
            c++;
            c2++;
            if (vr1 > vr2)
                return 1;
            if (vr1 < vr2)
                return -1;
        }
        return 0;
    }
};