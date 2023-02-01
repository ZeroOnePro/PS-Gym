#include <bits/stdc++.h>

using namespace std;

int n, m, cnt;

bool cut(int c, bool is_mul) {
  if (is_mul) c -= 1;
  if (c <= m) {
    cnt += is_mul ? c + 1 : c;
    m -= c;
  } else {
    cnt += m;
    return true;
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  vector<int> not_multi;  // 10보다 크면서 10의 배수가 아닌 것
  vector<int> cake;       // 10보다 크면서 10의 배수인 것
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    if (c == 10) cnt += 1;
    if (c > 10) {
      if (c % 10 == 0)
        cake.push_back(c);
      else
        not_multi.push_back(c);
    }
  }
  sort(cake.begin(), cake.end());
  sort(not_multi.begin(), not_multi.end());
  cake.insert(cake.end(), not_multi.begin(), not_multi.end());
  while (m > 0 && !cake.empty()) {
    int cur = cake.front();
    if (cut(cur / 10, cur % 10 == 0)) break;
    cake.erase(cake.begin());
  }
  cout << cnt;
  return 0;

  /**
   * 1. 알고리즘 정당성
   * 10보다 크면서 제일 작은 정수를 먼저 잘라야 더 적은 커팅 횟수로 10을 더 많이
   * 만들 수 있기 때문에 그리디 문제란 건 쉽게 알 수 있었다
   * 하지만 10의 배수를 먼저 처리해줘야한다는 점을 간과했다
   * 10의 배수가 10의 배수가 아닌 수보다 10을 더 많이 만들 수 있음은 자명하다
   *
   * 2. 구현 이슈
   * 처음에는 자르고 나서 10보다 크면 우선순위 큐에 넣어서 다시 시작했는데
   * 나누기를 이용하면 그럴 필요가 없다 그것때문에 더 오래걸렸음
   *
   */