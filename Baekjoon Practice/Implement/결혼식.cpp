#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> friends[10001];
bool check[501];
int edges[501];

void bfs(int start) {
  queue<int> q;
  check[start] = true;
  q.push(start);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int i = 0; i < (int)friends[node].size(); ++i) {
      int next = friends[node][i];
      if (!check[next]) {
        edges[next] = edges[node] + 1;
        check[next] = true;
        q.push(next);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  int invited = 0;
  cin >> n >> m;
  int from, to;
  for (int i = 0; i < m; ++i) {
    cin >> from >> to;
    friends[from].push_back(to);
    friends[to].push_back(from);
  }
  bfs(1);
  for (int i = 2; i <= n; ++i) {
    if (edges[i] > 0 && edges[i] <= 2) {
      invited += 1;
    }
  }
  cout << invited << '\n';
  return 0;
}