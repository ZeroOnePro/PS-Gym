#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool check(string s) {
  char ch = s[0];
  for (char c : s)
    if (ch != c) return false;
  return true;
}

bool dfs(string bin) {
  int len = bin.length();
  // leaf이거나 자식 트리가 포화트린 경우
  if (len == 1 || check(bin)) return true;
  int mid = len / 2 - !(len & 1);
  if (bin[mid] == '0') return false;
  return dfs(bin.substr(0, mid)) && dfs(bin.substr(mid + 1));
}

string to_binary(ll x) {
  string bin = "";
  stack<int> s;
  while (x != 0) {
    s.push(x & 1);
    x >>= 1;
  }
  while (!s.empty()) {
    bin += to_string(s.top());
    s.pop();
  }
  return bin;
}

vector<int> solution(vector<long long> numbers) {
  vector<int> answer;
  vector<ll> full;
  for (int i = 0; i <= 50; ++i) full.push_back((1 << i) - 1);
  for (ll n : numbers) {
    string bin = to_binary(n);
    int padding = 0;
    for (ll f : full)
      if (f >= bin.length()) {
        padding = f - bin.length();
        break;
      }
    for (int i = 0; i < padding; ++i) bin = "0" + bin;
    answer.push_back(dfs(bin));
  }
  return answer;
}