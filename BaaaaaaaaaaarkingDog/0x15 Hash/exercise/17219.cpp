#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> memo;
  for (int i = 0; i < n; ++i) {
    string site, pw;
    cin >> site >> pw;
    memo[site] = pw;
  }
  for (int i = 0; i < m; ++i) {
    string site;
    cin >> site;
    cout << memo[site] << '\n';
  }
  return 0;
}