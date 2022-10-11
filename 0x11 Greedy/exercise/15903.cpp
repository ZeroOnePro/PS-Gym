#include <bits/stdc++.h>

using namespace std;

/**
 * accumulate 사용 시 주의점
 * 처음에 누적합의 초기값을 설정할 때 사용한 컨테이너의 타입으로
 * 캐스팅해줘야한다 그냥 0 써넣으면 int형으로 인식하고 리턴값도 int로
 * 정해지기때문에 오버플로가 나도 뭐가 원인인지 모른다
 */

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<long long> c(n, 0);
  for (int i = 0; i < n; ++i) cin >> c[i];
  while (m--) {
    sort(c.begin(), c.end());
    long long sum = c[0] + c[1];
    c[0] = c[1] = sum;
  }
  cout << accumulate(c.begin(), c.end(), (long long)0);
  return 0;
}