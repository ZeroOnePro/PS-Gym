#include <bits/stdc++.h>

using namespace std;

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
  multimap<int, int, greater<int>> jewels;
  multiset<int> bags;
  for (int i = 0; i < n; ++i) {
    int mass, value;
    cin >> mass >> value;
    jewels.insert({value, mass});
  }
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    bags.insert(c);
  }
  long long ans = 0;
  for (auto it = jewels.begin(); it != jewels.end(); ++it) {
    auto [v, m] = *it;
    auto bag = bags.lower_bound(m);
    if (bag == bags.end()) continue;
    ans += v;
    bags.erase(bag);
  }
  cout << ans;
  return 0;
}