class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int f = 0;
        for(int i = nums.size()-1;i>=1;i--){
            if(nums[i]<=nums[i-1])continue;
            f = 1;
            int t = nums[i-1];
            reverse(nums.begin()+i,nums.end());
            for(int j = i;j<nums.size();j++){
                if(nums[j]>t){
                    swap(nums[j],nums[i-1]);
                    break;
                }
            }
            break;
            // nums[i-1]=
        }
        if(f==0)
        reverse(nums.begin(),nums.end());
    }
};