class Solution
{
public:
    int p(vector<int> &nums, int l, int h)
    {
        int pivot = nums[l];
        int i = l + 1;
        int j = h;
        while (i <= j)
        {
            if (nums[i] > pivot && nums[j] < pivot)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] <= pivot)
            {
                i++;
            }
            if (nums[j] >= pivot)
            {
                j--;
            }
        }
        swap(nums[l], nums[j]);
        return j;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int l = 0, h = nums.size() - 1;
        while (1)
        {
            int idx = p(nums, l, h);
            if (idx == k - 1)
                return nums[idx];
            if (idx >= k)
            {
                h = idx - 1;
            }
            else
            {
                l = idx + 1;
            }
        }
        return -1;
    }
};