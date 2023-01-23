#include <bits/stdc++.h>

using namespace std;

const int range = 25;

int n;
int dist[range][range];
bool is_not_used[range][range];
bool is_impossible = false;

void floyd() {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (k == i || k == j || i == j) continue;
        if (dist[i][j] == dist[i][k] + dist[k][j]) is_not_used[i][j] = true;
        if (dist[i][j] > dist[i][k] + dist[k][j]) is_impossible = true;
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> dist[i][j];
  floyd();
  if (is_impossible) {
    cout << -1 << '\n';
    return 0;
  }
  int sum = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (!is_not_used[i][j]) sum += dist[i][j];
  cout << sum / 2 << '\n';
  return 0;
}