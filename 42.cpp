class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int l = 0, cl = 0, f = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cl++;
                l = max(cl, l);
            }
            else
                cl = 0;
        }
        return l;
    }
};