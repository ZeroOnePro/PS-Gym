#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
  int answer = 0;
  for (int i = 0; i < section.size();) {
    auto lb = upper_bound(section.begin(), section.end(), section[i] + m - 1);
    i = lb - section.begin();
    answer += 1;
  }
  return answer;
}