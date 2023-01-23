#include <bits/stdc++.h>

using namespace std;

#define d first
#define w second

int n;
int ans, cnt;
pair<int, int> egg[10];

void crack_egg(int cur) {
  if (cur == n) {
    ans = max(ans, cnt);
    return;
  }
  if (cnt == n - 1 || egg[cur].d <= 0) {
    crack_egg(cur + 1);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (i == cur || egg[i].d <= 0) continue;
    egg[cur].d -= egg[i].w;
    egg[i].d -= egg[cur].w;
    cnt += (egg[cur].d <= 0) + (egg[i].d <= 0);
    crack_egg(cur + 1);
    cnt -= (egg[cur].d <= 0) + (egg[i].d <= 0);
    egg[cur].d += egg[i].w;
    egg[i].d += egg[cur].w;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> egg[i].d >> egg[i].w;
  crack_egg(0);
  cout << ans;
  return 0;
}