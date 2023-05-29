#include <bits/stdc++.h>

using namespace std;

const int range = 10;

int mx;
int seq[range];
bool is_used[range];

vector<vector<int>> d;

int calc(int n, int k) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (k >= d[seq[i]][0]) {
      k -= d[seq[i]][1];
      cnt += 1;
    }
  }
  return cnt;
}

void all_case(int cur, int n, int k) {
  if (cur == n) {
    // 여기서 피로도 계산해서 갱신
    mx = max(mx, calc(n, k));
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (is_used[i]) continue;
    is_used[i] = true;
    seq[cur] = i;
    all_case(cur + 1, n, k);
    is_used[i] = false;
  }
}

int solution(int k, vector<vector<int>> dungeons) {
  int answer = -1;
  d = dungeons;
  all_case(0, dungeons.size(), k);
  answer = mx;
  return answer;
}