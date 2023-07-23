string kthPermutation(int n, int k)
{
    int fac = 1;
    for (int i = 2; i <= n; i++)
    {
        fac *= i;
    }
    string ans = "";
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        fac = fac / (n - i);
        int z = k / fac;
        if (k % fac != 0)
            z++;
        k -= (z - 1) * fac;
        if (k < 0)
            k = 0;
        if (z == 0)
            z = 1;
        int c = 1;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == 0 && c == z)
            {
                ans += to_string(j + 1);
                v[j] = 1;
                break;
            }
            if (v[j] == 0)
                c++;
        }
    }
    return ans;
}
