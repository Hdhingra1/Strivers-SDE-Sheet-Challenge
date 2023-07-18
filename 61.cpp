double check(double mid, int n)
{
    double ans = 1;
    while (n--)
    {
        ans *= mid;
    }
    return ans;
}
int NthRoot(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (pow(mid, n) == m)

            return mid;

        else if (pow(mid, n) > m)

            high = mid - 1;

        else

            low = mid + 1;
    }

    return -1;
    // cout<<(int)(pow(low,n)-m)<<endl;
    // if(pow(low,n)==m)return low;
    // return -1;
    // int t = (int)low;
    // t++;
    // return t;
    // cout<<t<<endl;
    // if(t-low==0){int k = t;return k;}
    // return -1;
}