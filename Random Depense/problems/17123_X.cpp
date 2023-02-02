#include <bits/stdc++.h>

using namespace std;

const int range = 1e3 + 5;

int t, n, m, r1, c1, r2, c2, v;

int r[range];  // 각 행에 더해질 값들을 누적, r[i] = i번째 행 누적합
int c[range];  // 각 열에 더해질 값들을 누적, c[i] = i번째 열 누적합

// 1-indexed임에 주의하라
inline void input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int in;
      cin >> in;
      r[i] += in;
      c[j] += in;
    }
}

// 연산적용
inline void operate() {
  for (int i = 0; i < m; ++i) {
    cin >> r1 >> c1 >> r2 >> c2 >> v;
    r1--;
    c1--;
    r2--;
    c2--;
    for (int i = r1; i <= r2; ++i) r[i] += (c2 - c1 + 1) * v;
    for (int i = c1; i <= c2; ++i) c[i] += (r2 - r1 + 1) * v;
  }
}

inline void print() {
  for (int i = 0; i < n; ++i) cout << r[i] << ' ';
  cout << '\n';
  for (int i = 0; i < n; ++i) cout << c[i] << ' ';
  cout << '\n';
}

inline void init() {
  fill(r, r + n, 0);
  fill(c, c + n, 0);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    input();
    operate();
    print();
    init();
  }
  return 0;
}