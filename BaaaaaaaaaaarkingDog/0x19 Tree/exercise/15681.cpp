#include <bits/stdc++.h>

using namespace std;

const int range = 1e5 + 5;

int n, r, q;
vector<int> adj[range];
int subtree[range];

void count_subtree_nodes(int cur) {
  subtree[cur] = 1;
  for (int nxt : adj[cur]) {
    if (subtree[nxt] >= 1) continue;
    count_subtree_nodes(nxt);
    subtree[cur] += subtree[nxt];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> r >> q;
  for (int i = 0; i < n - 1; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  count_subtree_nodes(r);
  while (q--) {
    int v;
    cin >> v;
    cout << subtree[v] << '\n';
  }
  return 0;
}