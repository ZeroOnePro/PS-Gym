#include <bits/stdc++.h>

using namespace std;

int card[500002];
int n;

int lower_idx(int target) {
  int st = 0;
  int en = n;
  while (st < en) {
    int mid = (st + en) / 2;
    if (card[mid] >= target)
      en = mid;
    else
      st = mid + 1;
  }
  return st;
}

int upper_idx(int target) {
  int st = 0;
  int en = n;
  while (st < en) {
    int mid = (st + en) / 2;
    if (card[mid] > target)
      en = mid;
    else
      st = mid + 1;
  }
  return st;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int elem;
    cin >> elem;
    card[i] = elem;
  }
  sort(card, card + n);
  int m;
  cin >> m;
  while (m--) {
    int elem;
    cin >> elem;
    cout << upper_idx(elem) - lower_idx(elem) << ' ';
  }
  return 0;
}