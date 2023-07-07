class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long long ans = 1;
        int temp = n + m - 2;
        int t2 = n - 1;
        int t3 = m - 1;
        for (int i = 1; i <= t3; i++)
        {
            ans = ans * (t2 + i) / i;
            // if(i<=t2)
            //     ans/=i;
            // if(i<=t3)
            //     ans/=i;
        }
        // for(int i = 1;i<=t2;i++){
        //     ans/=i;
        // }
        // temp = m-1;
        // for(int i = 1;i<=temp;i++){
        //     ans/=i;
        // }
        return (int)ans;
    }
};