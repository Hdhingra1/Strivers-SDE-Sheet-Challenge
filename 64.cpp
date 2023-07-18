class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size(), l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[l])
            {
                if (target >= nums[l] && target < nums[mid])
                {
                    h = mid - 1;
                }
                else
                    l = mid + 1;
            }
            else
            {
                if (target > nums[h] || target < nums[mid])
                {
                    h = mid - 1;
                }
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};