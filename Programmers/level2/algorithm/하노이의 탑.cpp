#include <bits/stdc++.h>

#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr)

using namespace std;

void hanoi(int st, int en, int n, vector<vector<int>>& v) {
  if (n == 1) {
    v.push_back({st, en});
    return;
  }
  hanoi(st, 6 - st - en, n - 1, v);
  v.push_back({st, en});
  hanoi(6 - st - en, en, n - 1, v);
}

vector<vector<int>> solution(int n) {
  fastio;

  vector<vector<int>> answer;
  hanoi(1, 3, n, answer);
  return answer;
}