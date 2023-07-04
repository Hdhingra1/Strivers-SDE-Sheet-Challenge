class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int h = n - 1;
        int l = 0;
        int f = 0;
        int mid;
        while( l <= h){
             mid = (l+h)/2;
            if(mat[mid][0]<=target&& mat[mid][m-1]>= target){
                f = 1;
                break;
            }
            else if(mat[mid][0]> target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(f==0)return false;
        l = 0;
        h  = m-1;
        while(l <= h){
            int mid2 = (l+h)/2;
            if(mat[mid][mid2]==target)return true;
            else if(mat[mid][mid2]<target)
                l = mid2 + 1;
            else 
                h = mid2 - 1;
        }
        return false;
    }
};