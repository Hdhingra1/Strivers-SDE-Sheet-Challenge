class Solution
{
public:
    void fun(int idx, int sum, int target, vector<vector<int>> &ans, vector<int> &c, vector<int> &ds)
    {
        if (sum == target)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = idx; i < c.size(); i++)
        {
            if (i != idx && c[i - 1] == c[i])
            {
                continue;
            }
            if (sum + c[i] <= target)
            {
                ds.push_back(c[i]);
                fun(i + 1, sum + c[i], target, ans, c, ds);
                ds.pop_back();
            }
            else
                break;
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &c, int target)
    {
        sort(c.begin(), c.end());
        vector<int> ds;
        vector<vector<int>> ans;
        fun(0, 0, target, ans, c, ds);
        return ans;
    }
};