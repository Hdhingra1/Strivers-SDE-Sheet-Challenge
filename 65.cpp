class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int f = (n + m + 1) / 2;
        int l1 = f - m;
        if (l1 < 0)
            l1 = 0;
        int h1 = min(f, n);
        while (l1 <= h1)
        {
            int cnt1 = (l1 + h1) / 2;
            int cnt2 = f - cnt1;
            int a = cnt1 == 0 ? INT_MIN : nums1[cnt1 - 1];
            int b = cnt2 == 0 ? INT_MIN : nums2[cnt2 - 1];
            int c = cnt1 == n ? INT_MAX : nums1[cnt1];
            int d = cnt2 == m ? INT_MAX : nums2[cnt2];
            if (a <= d && b <= c)
            {
                if ((n + m) % 2 == 1)
                {
                    return max(a, b);
                }
                else
                    return (max(a, b) + min(c, d)) / 2.0;
            }
            else if (a > d)
            {
                h1 = cnt1 - 1;
            }
            else
            {
                l1 = cnt1 + 1;
            }
        }
        return 0;
    }
};