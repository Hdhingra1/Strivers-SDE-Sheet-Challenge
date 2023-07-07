class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = target - nums[i];
            if (mp[t] != 0)
            {
                if (mp[t] == -1)
                    ans.push_back(0);
                else
                    ans.push_back(mp[t]);
                ans.push_back(i);
                break;
            }
            if (i == 0)
                mp[nums[i]] = -1;
            else
                mp[nums[i]] = i;
        }
        return ans;
    }
};