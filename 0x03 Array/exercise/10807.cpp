#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, v;
  cin >> n;
  vector<int> freq(201);
  for (int i = 0; i < n; ++i) {
    int input;
    cin >> input;
    if (input < 0) {
      freq[input + 201] += 1;
    } else {
      freq[input] += 1;
    }
  }
  cin >> v;
  if (v < 0)
    cout << freq[v + 201] << '\n';
  else
    cout << freq[v] << '\n';
  return 0;
}