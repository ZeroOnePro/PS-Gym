#include <bits/stdc++.h>

using namespace std;

map<string, bool> vis;
int ans;

bool check(string a, string b){
    int cnt = 0;
    int len = a.length();
    for(int i=0; i<len; ++i) if(a[i] != b[i]) cnt += 1;
    return cnt <= 1;
}

void dfs(string cur, string target, vector<string> words, int depth){
    vector<string> cand;
    if(cur == target){
        ans = depth;
        return;
    }
    for(int i=0; i<words.size(); ++i){
        if(vis[words[i]]) continue;
        if(check(cur, words[i])) {
            vis[words[i]] = true;
            cand.push_back(words[i]);
        }
    }
    for(string c : cand) dfs(c, target, words, depth+1);
}

int solution(string begin, string target, vector<string> words) {
    for(string w : words) vis[w] = false;
    dfs(begin, target, words, 0);
    return ans;
}