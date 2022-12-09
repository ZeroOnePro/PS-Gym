#include <bits/stdc++.h>

using namespace std;

const int range = 505;
const int INF = 0x3f3f3f3f;

int n, m, q;

vector<pair<int, int>> dog_attack;
int attack_cost[range];
int dist[range][range];
int dp[range][range];

void floyd() {
  for (auto [cost, k] : dog_attack)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        dp[i][j] = min(dp[i][j], dist[i][k] + dist[k][j] +
                                     max(attack_cost[i],
                                         max(attack_cost[j], attack_cost[k])));
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    int attack;
    cin >> attack;
    dog_attack.push_back({attack, i});
    attack_cost[i] = attack;
  }
  for (int i = 1; i <= n; ++i) {
    fill(dist[i] + 1, dist[i] + n + 1, INF);
    fill(dp[i] + 1, dp[i] + n + 1, INF);
    dist[i][i] = 0;
    dp[i][i] = dog_attack[i - 1].first;
  }
  for (int i = 0; i < m; ++i) {
    int a, b, d;
    cin >> a >> b >> d;
    dist[a][b] = d;
    dist[b][a] = d;
  }
  sort(dog_attack.begin(), dog_attack.end());
  floyd();
  while (q--) {
    int s, t, d;
    cin >> s >> t;
    d = dist[s][t];
    if (d == INF)
      d = -1;
    else
      d = dp[s][t];
    cout << d << '\n';
  }
  return 0;
}