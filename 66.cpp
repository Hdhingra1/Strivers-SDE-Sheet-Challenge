class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int l = k - m;
        if (l < 0)
            l = 0;
        int h = min(k, n);
        while (l <= h)
        {
            int c1 = (l + h) / 2;
            int c2 = k - c1;
            int a = c1 == 0 ? INT_MIN : arr1[c1 - 1];
            int b = c2 == 0 ? INT_MIN : arr2[c2 - 1];
            int c = c1 == n ? INT_MAX : arr1[c1];
            int d = c2 == m ? INT_MAX : arr2[c2];
            if (a <= d && b <= c)
            {
                return max(a, b);
            }
            else if (a > d)
            {
                h = c1 - 1;
            }
            else
                l = c1 + 1;
        }
        return 0;
    }
};