#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int k;
  while (1) {
    cin >> k;
    if (!k)
      return 0;
    vector<int> lotto(k);
    for (int i = 0; i < k; ++i) {
      cin >> lotto[i];
    }
    // 1 6개 0 k-6개 짜리 순열을 만들어 permutation시킨다.
    // lotto[selcted[i]] == 1 면 선택, 0이면 미선택
    // selected[]를 shuffle 시킴..
    vector<int> selected(k);
    for (int i = 0; i < 6; ++i) {
      selected[i] = 1;
    }
    do {
      for (int i = 0; i < k; ++i) {
        if (selected[i]) {
          cout << lotto[i] << ' ';
        }
      }
      cout << '\n';
    } while (prev_permutation(selected.begin(), selected.end()));
    cout << '\n';
  }
  return 0;
}