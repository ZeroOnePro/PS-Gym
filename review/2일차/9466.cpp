#include <bits/stdc++.h>

using namespace std;

const int CYCLE_IN = -1;

void check_cycle(int node, vector<int>& term, vector<int>& state) {
  int cur = node;
  while (true) {
    state[cur] = node;
    cur = term[cur];
    if (state[cur] == node) {
      while (state[cur] != CYCLE_IN) {
        state[cur] = CYCLE_IN;
        cur = term[cur];
      }
      return;
    } else if (state[cur] != 0)
      return;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, cnt = 0;
    cin >> n;
    vector<int> term(n + 1), state(n + 1);
    for (int i = 1; i <= n; ++i) cin >> term[i];
    for (int i = 1; i <= n; ++i)
      if (state[i] == 0) check_cycle(i, term, state);
    for (int i = 1; i <= n; ++i) cnt += (state[i] == CYCLE_IN);
    cout << n - cnt << '\n';
  }
  return 0;
}