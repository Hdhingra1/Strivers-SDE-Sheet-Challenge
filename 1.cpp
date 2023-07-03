class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int c = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    if(j==0){c=1;continue;}
                    mat[0][j]=0;
                }
            }
        }
        for(int i = 1;i<m;i++){
            if(mat[0][i]==0){
                for(int j = 1;j<n;j++)
                    mat[j][i]=0;
            }
        }
        for(int i = 0;i<n;i++){
            if(mat[i][0]==0){
                for(int j = 1;j<m;j++)
                    mat[i][j]=0;
            }
        }
        if(c==1){
            for(int j = 0;j<n;j++)
                mat[j][0]=0;
        }
    }
};