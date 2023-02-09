#include <bits/stdc++.h>

using namespace std;

const int range = 3 * 1e5 + 5;

int n, m;
int jewel[range];

// 질투심의 최대가 x일 때 나눠주는게 가능한가?
bool possible(int x) {
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    cnt += jewel[i] / x;
    cnt += (jewel[i] % x != 0);
  }
  return cnt > n;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> jewel[i];
  int st = 1, en = 1e9;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (possible(mid))
      st = mid + 1;
    else
      en = mid - 1;
  }
  cout << st;
  return 0;
}