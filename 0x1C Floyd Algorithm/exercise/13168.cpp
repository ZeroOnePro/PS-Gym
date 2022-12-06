#include <bits/stdc++.h>

using namespace std;

const int range = 105;
const int INF = 0x3f3f3f3f;

int n, r, m, k;

string discount[] = {"ITX-Saemaeul", "ITX-Cheongchun", "Mugunghwa", "S-Train",
                     "V-Train"};
unordered_map<string, int> id;
vector<int> tour;
double naeilo[range][range];
double dist[range][range];

void floyd() {
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j || k == i || k == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        naeilo[i][j] = min(naeilo[i][j], naeilo[i][k] + naeilo[k][j]);
      }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> r;
  for (int i = 0; i < n; ++i) {
    string city;
    cin >> city;
    id[city] = i;
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    string city;
    cin >> city;
    tour.push_back(id[city]);
  }
  cin >> k;
  for (int i = 0; i < n; ++i) {
    fill(dist[i], dist[i] + n, INF);
    fill(naeilo[i], naeilo[i] + n, INF);
    dist[i][i] = 0;
    naeilo[i][i] = 0;
  }
  for (int i = 0; i < k; ++i) {
    string type, src, des;
    double cost;
    cin >> type >> src >> des >> cost;
    int st = id[src], en = id[des];
    // st에서 en으로 가는 교통수단은 다수개일 수 있다
    dist[st][en] = min(dist[st][en], cost);
    dist[en][st] = min(dist[en][st], cost);
    // 할인 적용
    for (int j = 0; j < 5; ++j) {
      if (type == discount[j]) {
        if (j <= 2)
          cost = 0;
        else if (j >= 3)
          cost /= 2;
      }
    }
    naeilo[st][en] = min(naeilo[st][en], cost);
    naeilo[en][st] = min(naeilo[en][st], cost);
  }
  floyd();
  double no_ticket = 0, ticket = 0;
  for (int i = 1; i < m; ++i) {
    no_ticket += dist[tour[i - 1]][tour[i]];
    ticket += naeilo[tour[i - 1]][tour[i]];
  }
  ticket += r;
  cout << (no_ticket > ticket ? "Yes" : "No") << '\n';
  return 0;
}