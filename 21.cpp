class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        for (auto it : nums)
        {
            set.insert(it);
        }
        int l = 0, ans = 0;
        for (auto it : nums)
        {
            if (set.find(it - 1) == set.end())
            {
                l = 1;
                int t = it + 1;
                while (set.find(t) != set.end())
                {
                    l++;
                    t++;
                }
                ans = max(l, ans);
            }
        }
        return ans;
    }
};