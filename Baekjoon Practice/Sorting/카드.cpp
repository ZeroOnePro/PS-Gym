#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> card(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> card[i];
  }
  sort(card.begin(), card.end());
  // counting function
  long long cursor = card[0];
  vector<pair<long long, long long>> maximum_pair;
  long long count = 0;
  // long long find;
  for (int i = 0; i < n; ++i) {
    if (cursor == card[i]) {
      count += 1;
    } else {
      maximum_pair.push_back(make_pair(count, cursor)); // 이전의 값 저장
      count = 1;
      cursor = card[i];
    }
  }
  maximum_pair.push_back(make_pair(count, cursor));
  /*
  for (pair<long long, long long> p : maximum_pair) {
          cout << p.first << ' ' << p.second << '\n';
  }*/
  // first기준 내림차순 정렬
  sort(maximum_pair.begin(), maximum_pair.end(),
       [&maximum_pair](pair<long long, long long> a,
                       pair<long long, long long> b) -> bool {
         if (a.first == b.first) {
           return a.second < b.second;
         }
         return a.first > b.first;
       });
  cout << maximum_pair[0].second << '\n';
  return 0;
}