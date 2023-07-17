class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // 	vector<pair<int,int>> v;
        // 	for(int i = 0;i<n;i++){
        // 	    v.push_back({arr[i],0});
        // 	    v.push_back({dep[i],1});
        // 	}
        sort(arr, arr + n);
        sort(dep, dep + n);
        int ans = 0, l = 0, i = 0, j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                i++;
                l++;
            }
            else
            {
                j++;
                l--;
            }
            ans = max(ans, l);
        }
        return ans;
    }
};