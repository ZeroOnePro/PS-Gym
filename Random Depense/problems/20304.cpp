#include <bits/stdc++.h>

using namespace std;

const int range = 100'005;

vector<int> mman, pman, mwoman, pwoman;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    if (h < 0)
      mman.push_back(h);
    else
      pman.push_back(h);
  }
  for (int i = 0; i < n; ++i) {
    int h;
    cin >> h;
    if (h < 0)
      mwoman.push_back(h);
    else
      pwoman.push_back(h);
  }

  sort(mman.begin(), mman.end());
  sort(pman.begin(), pman.end());
  sort(mwoman.begin(), mwoman.end());
  sort(pwoman.begin(), pwoman.end());

  // 1. mman - pwoman 매칭
  int st = 0, en = pwoman.size() - 1;
  while (true) {
    if (st >= mman.size() || en < 0) break;
    // 쌍이 맞으면 포인터 둘 다 이동
    // 쌍이 안맞으면 en 이동
    if (-mman[st] > pwoman[en]) {
      st += 1;
      en -= 1;
      cnt += 1;
    } else
      en -= 1;
  }
  // 2. pman - mwoman 매칭
  st = 0, en = pman.size() - 1;
  while (true) {
    if (st >= mwoman.size() || en < 0) break;
    // 쌍이 맞으면 포인터 둘 다 이동
    // 쌍이 안맞으면 en 이동
    if (-mwoman[st] > pman[en]) {
      st += 1;
      en -= 1;
      cnt += 1;
    } else
      en -= 1;
  }
  cout << cnt;
  return 0;
}