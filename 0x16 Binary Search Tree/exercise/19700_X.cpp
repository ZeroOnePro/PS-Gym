#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int, int, greater<int>> stu;
  multiset<int> team;
  while (n--) {
    int h, k;
    cin >> h >> k;
    stu.insert({h, k});
  }
  /* To do
   키 큰 순으로 팀에 배치
   가장 k_i보다 크거나 같은 팀에는 들어갈 수 없으므로 k_i보다 작은 것 중에
   제일 큰 것에 넣어줘야함 한 팀에 최대한 많이 몰아넣어야 팀 수가 최소가
   되기 때문
  */
  while (!stu.empty()) {
    auto [h, k] = *stu.begin();
    auto lb = team.lower_bound(k);
    // map이 비었을 때는 begin과 end가 같은 값을 갖는다
    if (lb != team.begin()) {
      // k와 같거나 크므로 k보다 작으면서 제일 큰수는 lb 앞에 있음
      lb = prev(lb);
      team.erase(lb);
      team.insert(*lb + 1);
    } else
      team.insert(1);
    stu.erase(h);
  }
  cout << team.size();
  return 0;
}