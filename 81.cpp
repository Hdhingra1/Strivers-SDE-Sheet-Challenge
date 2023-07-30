#include <bits/stdc++.h>
class Node{
    public:
        Node* links[2];
    bool is(int i){
        return links[i] != NULL;
    }
};
class Trie{
    Node * root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int x){
        Node *tmp = root;
        for(int i = 31;i>=0;i--){
            int bit = (x>>i)&(1);
            if(!tmp->is(bit)){
                tmp->links[bit] = new Node();
            }
            tmp = tmp->links[bit];
        }
    }
    int mx(int a){
        Node *tmp = root;
        int ans = 0;
        for(int i = 31;i>=0;i--){
            int bit = (a>>i)&(1);
            int d = 1-bit;
            if(tmp->is(d)){
                ans= ans|(1<<i);
                tmp = tmp->links[d];
            }
            else{
                tmp = tmp->links[bit];
            }
        }
        return ans;
    }

};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie t;
	sort(arr.begin(),arr.end());
	vector<pair<int,pair<int,int>>> q;
	for(int i = 0; i < queries.size();i++){
		q.push_back({queries[i][1],{queries[i][0],i}});
	}
	sort(q.begin(),q.end());
	vector<int> ans(q.size(),0);
	int idx = 0;
	for(auto it: q){
		while(idx<arr.size()&&arr[idx]<=it.first){
			t.insert(arr[idx]);
			idx++;
		}
		if(idx==0){
			ans[it.second.second]=-1;
			continue;	
		}
		ans[it.second.second]=t.mx(it.second.first);
	}
	return ans;
}