#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
  int answer = 0;
  sort(routes.begin(), routes.end(), [](vector<int>& a, vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
  });
  int n = routes.size();
  for (int i = 0; i < n;) {
    int en = routes[i][1];
    while (i < n && en >= routes[i][0] && en <= routes[i][1]) i += 1;
    answer += 1;
  }
  return answer;
}
