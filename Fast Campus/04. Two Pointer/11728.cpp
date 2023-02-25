#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1000002];
int b[1000002];
int merged[2000004];

void merge_sort() {
  int a_cur = 0, b_cur = 0, index = 0;
  while (index < n + m) {
    if (a_cur == n)
      merged[index++] = b[b_cur++];
    else if (b_cur == m)
      merged[index++] = a[a_cur++];
    else if (a[a_cur] <= b[b_cur])
      merged[index++] = a[a_cur++];
    else if (a[a_cur] >= b[b_cur])
      merged[index++] = b[b_cur++];
    else
      continue;
  }
}

void print_result(int n, int *list) {
  for (int i = 0; i < n; ++i) {
    cout << list[i] << ' ';
  }
  cout << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  merge_sort();
  print_result(n + m, merged);
  return 0;
}