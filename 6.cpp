class Solution {
public:
    int maxProfit(vector<int>& p) {
        int b = p[0];
        int ans = 0;
        int s = p[0];
        for(int it:p){
            if(it>s){
                s = it;
                ans = max(ans,s-b);
            }
            if(it<b){
                b = it;
                s = it;
            }
            
        }
        return ans;
    }
};