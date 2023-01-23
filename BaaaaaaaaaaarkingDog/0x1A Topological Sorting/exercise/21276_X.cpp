#include <bits/stdc++.h>

using namespace std;

const int range = 1'005;

int n, m;

string name[range];
unordered_map<string, int> id;
vector<int> adj[range];
map<int, set<int>> p2c;
int deg[range];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  queue<int> q;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> name[i];
  // 사전순 출력을 위함
  sort(name + 1, name + n + 1);
  // id 부여
  for (int i = 1; i <= n; ++i) id[name[i]] = i;
  cin >> m;
  // 조상 -> 자식
  for (int i = 0; i < m; ++i) {
    string an, de;
    cin >> de >> an;
    adj[id[an]].push_back(id[de]);
    deg[id[de]] += 1;
  }
  vector<int> root;
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 0) {
      root.push_back(i);
      q.push(i);
    }
  cout << root.size() << '\n';
  for (int r : root) cout << name[r] << ' ';
  cout << '\n';
  // 부모 - 자식 관계는 indegree가 1차이 난다는 점을 활용한다
  // 이 문제에서 자손은 자신의 모든 조상과 연결되있기 때문에 가능한 것
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (adj[cur].size() == 0) p2c[cur] = {};
    for (int nxt : adj[cur]) {
      if (deg[nxt] - deg[cur] == 1) p2c[cur].insert(nxt);
      deg[nxt] -= 1;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
  for (auto [i, child] : p2c) {
    cout << name[i] << ' ' << child.size() << ' ';
    for (int c : child) cout << name[c] << ' ';
    cout << '\n';
  }
  return 0;
}