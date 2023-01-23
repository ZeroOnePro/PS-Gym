#include <bits/stdc++.h>

using namespace std;

/**
 * 앞으로 가장 오랫동안 사용되지 않을 것을 교체
 *
 * 캐시 알고리즘 중 최적으로 알려져 있음
 */

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, ans = 0;
  cin >> n >> k;
  list<int> cache;
  vector<int> task;
  for (int i = 0; i < k; ++i) {
    int in;
    cin >> in;
    task.push_back(in);
  }
  for (int i = 0; i < k; ++i) {
    // 캐시에 task[i]가 없을 때
    if (find(cache.begin(), cache.end(), task[i]) == cache.end()) {
      int len = cache.size();
      if (len < n) {
        cache.push_back(task[i]);
      } else {
        int offset = 0;
        auto it = cache.begin();
        for (auto iter = cache.begin(); iter != cache.end(); ++iter) {
          int cur = k;
          for (int j = i + 1; j < k; ++j)
            if (*iter == task[j]) {
              cur = j;
              break;
            }
          if (cur > offset) {
            offset = cur;
            it = iter;
          }
        }
        cache.erase(it);
        cache.push_back(task[i]);
        ans += 1;
      }

      // for (int i : cache) cout << i << ' ';
      // cout << '\n';
    }
  }
  cout << ans;
  return 0;
}