class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans={{1}};
        n--;
        int i = 0; 
        while(n--){
            vector<int> t = {1};
            for(int j = 0;j<ans[i].size()-1;j++){
                int temp = ans[i][j]+ans[i][j+1];
                t.push_back(temp);
            }
            t.push_back(1);
            ans.push_back(t);
            i++;
        }
        return ans;
    }
};