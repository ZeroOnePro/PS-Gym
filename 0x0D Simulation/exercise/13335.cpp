#include <bits/stdc++.h>

using namespace std;

int n, w, l;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> w >> l;
  // 현재 살펴보는 트럭(다리에 올릴 수 있는지 검사), 트럭 무게 총량, 총 걸리는
  // 시간(정답)
  int cur = 0, tw = 0, tot = 0;
  queue<int> q;
  vector<int> truck(n);
  for (auto& pt : truck) cin >> pt;
  while (true) {
    tot += 1;
    // 제일 앞 트럭 제거
    if (q.size() == w) {
      tw -= q.front();
      q.pop();
    }
    // 다리에 트럭을 올릴 수 있는 경우
    if (tw + truck[cur] <= l) {
      // 마지막 트럭이면 멈추기
      if (cur == n - 1) {
        tot += w;
        break;
      }
      tw += truck[cur];
      q.push(truck[cur]);
      cur += 1;
    }
    // 다리에 트럭 못올림, 0으로 추가
    else
      q.push(0);
  }
  cout << tot;
  return 0;
}