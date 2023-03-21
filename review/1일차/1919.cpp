#include <bits/stdc++.h>

using namespace std;

int freq[2][26];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int diff = 0;
  string a, b;
  cin >> a >> b;
  for (char ch : a) freq[0][ch - 'a'] += 1;
  for (char ch : b) freq[1][ch - 'a'] += 1;
  for (int i = 0; i < 26; ++i) diff += abs(freq[0][i] - freq[1][i]);
  cout << diff;
  return 0;
}