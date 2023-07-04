class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>> ans;
        int s = in[0][0];
        int e = in [0][0];
        for(auto it: in){
            if(it[0]<=e){
                e = max(e,it[1]);
            }
            else{
                ans.push_back({s,e});
                s = it[0];
                e = it[1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};