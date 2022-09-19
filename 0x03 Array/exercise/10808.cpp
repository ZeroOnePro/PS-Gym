#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string word;
  cin >> word;
  vector<int> alphbets(26);
  for (char ch : word) {
    alphbets[ch - 'a'] += 1;
  }
  for (int cnt : alphbets) cout << cnt << ' ';
  return 0;
}