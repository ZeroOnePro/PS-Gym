#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  vector<int> card;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    card.push_back(num);
  }
  cin >> m;
  sort(card.begin(), card.end());
  while (m--) {
    int target;
    cin >> target;
    cout << binary_search(card.begin(), card.end(), target) << ' ';
  }
  return 0;
}