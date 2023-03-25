#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int range = 100'005;

vector<bool> prime(range, true);

void clac_prime() {
  for (int i = 2; i * i <= range; ++i) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= range; j += i) prime[j] = false;
  }
}

int s, st, en;
int dist[1'000'005];

bool is_bound(int x) { return x >= st && x <= en; }

int bfs() {
  queue<int> q;
  fill(dist, dist + 1'000'005, -1);
  q.push(s);
  dist[s] = 0;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    for (int nxt : {cur / 3, cur / 2, cur + 1, cur - 1}) {
      if (nxt < 0 || nxt > 1'000'000) continue;
      if (dist[nxt] >= 0) continue;
      if (is_bound(nxt) && prime[nxt]) {
        return dist[cur] + 1;
      }
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  clac_prime();
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> s >> st >> en;
    if (s >= st && s <= en && prime[s])
      cout << 0 << '\n';
    else
      cout << bfs() << '\n';
  }
  return 0;
}