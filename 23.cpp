int subarraysXor(vector<int> &arr, int k)
{
    //    Write your code here.
    /*int cnt=0;
    for(int i=0;i<arr.size();i++){
      int xorx=0;
        for(int j=i;j<arr.size();j++){
           xorx^=arr[j];
           if(xorx==k) cnt++;
        }
    }
    return cnt;*/
    int xori = 0;
    int cnt = 0;
    unordered_map<int, int> um;
    um[xori]++;
    for (int i = 0; i < arr.size(); i++)
    {
        xori ^= arr[i];
        int xr = xori ^ k;
        cnt += um[xr];
        um[xori]++;
    }
    return cnt;
}