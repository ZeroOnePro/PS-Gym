#include <bits/stdc++.h>

using namespace std;

int k, n;
int cables[10005];

bool possible_length(long long len) {
  long long cnt = 0;
  for (int i = 0; i < k; ++i) cnt += cables[i] / len;
  return cnt >= n;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> k >> n;
  for (int i = 0; i < k; ++i) cin >> cables[i];
  long long st = 0, en = INT_MAX;
  while (st < en) {
    // mid를 이렇게 안하고 원래대로 st + en / 2로 하면 무한루프, st = en - 1인
    // 경우
    long long mid = (st + en + 1) / 2;
    if (possible_length(mid))
      // st도 n개 이상 나올 수 있는 길이니까 범위에서 제외하면 안 됨
      st = mid;
    else
      en = mid - 1;
  }
  cout << st;
  return 0;
}