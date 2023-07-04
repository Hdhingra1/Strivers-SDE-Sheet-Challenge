#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xr = 0;
	for(int i = 0;i < n; i++){
		xr = xr ^ (arr[i]);
		xr = xr ^ (i+1);
	}
	int bitn = 0;
	while(!(xr&(1<<bitn))){
		bitn++;
	}
	int o = 0,z = 0;
	for(int i = 0;i < n;i++){
		if(arr[i]&(1<<bitn)){
			o^= arr[i];
		}
		else{
			z^=arr[i];
		}
		if((i+1)&(1<<bitn)){
			o^= (i+1);
		}
		else{
			z^=(i+1);
		}
	}
	for(auto it: arr){
		if(it==o){
			return {z,o};
		}
	}
	return {o,z};
}
