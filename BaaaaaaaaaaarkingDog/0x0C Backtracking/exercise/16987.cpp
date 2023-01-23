#include <bits/stdc++.h>

using namespace std;

// 쌍으로 이뤄진게 8개되면 다 뽑은거
// (1,2) (2,1), (3,5) 이렇게있다 치자
// 1번으로 2번친거고 2번으로 1번친거고 3번으로 5번친거고
// (1, x), x는 1을 제외한 8보다 작거나 같은 자연수
// 이렇게 순서쌍만들어놓고 쳐서 몇 개 깨지는지 본다
// 그 중 최대가 정답

#define d first
#define w second

int n;
int ans = 0;
pair<int, int> egg[10];
int seq[8];

int crack_egg() {
  int cnt = 0;
  pair<int, int> tmp[10];
  for (int i = 1; i <= n; ++i) tmp[i] = egg[i];
  for (int i = 1; i <= n; ++i) {
    // i번 째 순서쌍 (x,y)에서 x와 y가 안깨졌는지 확인해야함
    // x가 때리는 계란 y는 맞는 계란
    int x = seq[i] / 10;
    int y = seq[i] % 10;
    if (tmp[x].d <= 0 || tmp[y].d <= 0) continue;
    tmp[x].d -= tmp[y].w;
    tmp[y].d -= tmp[x].w;
    cnt += (tmp[x].d <= 0);
    cnt += (tmp[y].d <= 0);
  }
  return cnt;
}

void make_set(int cur) {
  if (cur == n + 1) {
    ans = max(ans, crack_egg());
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (i == cur) continue;
    seq[cur] = cur * 10 + i;
    make_set(cur + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    egg[i] = {x, y};
  }
  make_set(1);
  cout << ans;
  return 0;
}