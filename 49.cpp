class Solution
{
public:
    void fun(vector<int> &arr, int N, vector<int> &ans, int i, int sum)
    {
        if (i == N)
        {
            ans.push_back(sum);
            return;
        }

        fun(arr, N, ans, i + 1, sum + arr[i]);
        fun(arr, N, ans, i + 1, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        fun(arr, N, ans, 0, 0);
        // vector<int> v(ans.begin(),ans.end());
        return ans;
    }
};