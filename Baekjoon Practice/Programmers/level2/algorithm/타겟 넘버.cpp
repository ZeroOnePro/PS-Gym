#include <bits/stdc++.h>

using namespace std;

int cnt;

void check_sum(int cur, int total, int sum, vector<int>& v) {
  if (cur == (int)v.size()) {
    if (total == sum) cnt += 1;
    return;
  }
  check_sum(cur + 1, total - v[cur], sum, v);
  check_sum(cur + 1, total + v[cur], sum, v);
}

int solution(vector<int> numbers, int target) {
  int answer = 0;
  check_sum(0, 0, target, numbers);
  answer = cnt;
  return answer;
}