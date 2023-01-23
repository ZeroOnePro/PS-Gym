#include <bits/stdc++.h>

using namespace std;

#define end_t first
#define start_t second

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  pair<int, int> sched[n + 1];
  for (int i = 0; i < n; ++i) cin >> sched[i].start_t >> sched[i].end_t;
  sort(sched,
       sched + n);  // 사전순 정렬이라 끝나는 시간 기준, 같다면 시작 시간 기준
  int cur = 0, conferences = 0;
  for (int i = 0; i < n; ++i) {
    if (cur > sched[i].start_t) continue;
    conferences += 1;
    cur = sched[i].end_t;
  }
  cout << conferences << '\n';
  return 0;
}