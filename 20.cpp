class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j != i + 1 && nums[j - 1] == nums[j])
                    continue;
                int l = j + 1, h = n - 1;
                while (l < h)
                {
                    long long s = nums[i];
                    s += nums[j];
                    s += nums[h];
                    s += nums[l];
                    if (s == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[h]});
                        l++;
                        h--;
                        while (l < h && nums[h] == nums[h + 1])
                        {
                            h--;
                        }
                        while (l < h && nums[l] == nums[l - 1])
                        {
                            l++;
                        }
                    }
                    else if (s > target)
                    {
                        h--;
                        while (l < h && nums[h] == nums[h + 1])
                        {
                            h--;
                        }
                    }
                    else
                    {
                        l++;
                        while (l < h && nums[l] == nums[l - 1])
                        {
                            l++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};