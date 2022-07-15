#include <bits/stdc++.h>

using namespace std;

#define value first
#define mass second

// 제일 값이 많이 나가는 순으로 세운다
// 값이 많이 나가는 순으로 차례대로 담을 수 있는 가방이 있는지 보고 담을 수
// 있으면 담고 못 담으면 다음으로 넘어간다 가방에 담을 때 보석의 무게보다 큰
// 가장 작은 정수의 가방을 선택한다
// 가방의 수가 최대 1억개로 1초에 통과하려면 가방 무게 검색을 이진 검색으로
// 해야한다

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  pair<int, int> jewels[300003];
  multiset<int> bags;
  int m, v;
  for (int i = 0; i < n; ++i) {
    cin >> jewels[i].mass >> jewels[i].value;
  }
  sort(jewels, jewels + n);
  int c;
  for (int i = 0; i < k; ++i) {
    cin >> c;
    bags.insert(c);
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    tie(v, m) = jewels[i];
    // 이진 검색 트리에서 lower_bound함수를 제공
    auto bag = bags.lower_bound(m);
    if (bag == bags.end()) continue;
    ans += v;
    bags.erase(bag);
  }
  cout << ans;
  return 0;
}