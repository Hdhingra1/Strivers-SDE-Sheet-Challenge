#include <bits/stdc++.h> 
class Node{
    public:
    Node* links[26];
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
};

int distinctSubstring(string &s) {
    Node * root = new Node();
    int count = 0;
    int n = s.size();
    int ans = 0;

    for(int i = 0;i<s.length();i++){
        Node * node = root;
        for(int j = i;j<n;j++){
          if (!node->containsKey(s[j])) {
              node->links[s[j]-'a'] = new Node();
              count++;
          }
          node = node->links[s[j]-'a'];
        }
    }
    return count;
}
