#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> result(n + m + 2, "");
  vector<string> don_listen(n + 1, "");
  vector<string> don_see(m + 1, "");
  for (int i = 0; i < n; ++i) {
    cin >> don_listen[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> don_see[i];
  }
  sort(don_listen.begin(), don_listen.end());
  sort(don_see.begin(), don_see.end());
  // set_intersection을 사용하려면 정렬이 되어있어야한다.
  auto itr = set_intersection(don_listen.begin(), don_listen.end(),
                              don_see.begin(), don_see.end(), result.begin());
  result.erase(itr, result.end()); // 반환값이, 삽입이 끝난후의 끝 지점 iterator
  cout << result.size() - 1;
  for_each(result.begin(), result.end(),
           [&result](string str) { // python의 map과 동일
             cout << str << '\n';
           });
  return 0;
}