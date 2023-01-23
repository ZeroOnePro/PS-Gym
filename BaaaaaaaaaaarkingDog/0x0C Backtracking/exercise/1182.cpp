#include <bits/stdc++.h>

using namespace std;

int n, s, cnt;
int seq[20];

void check_sum(int cur, int total) {
  // 부분수열의 최대 길이는 n
  // 길이가 n이 되기 이전에 합을 만족했더라도, 나머지 원소는 0이므로
  // 길이가 n이 되고 나서 검사해도 무관
  if (cur == n) {
    if (total == s) cnt++;
    return;
  }
  // 현재 원소를 결과에 미포함
  check_sum(cur + 1, total);
  // 현재 원소를 결과에 포함
  check_sum(cur + 1, total + seq[cur]);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) cin >> seq[i];
  // 경우의 수에서 공집합 제거
  check_sum(0, 0);
  if (!s) cnt--;
  cout << cnt;
  return 0;
}