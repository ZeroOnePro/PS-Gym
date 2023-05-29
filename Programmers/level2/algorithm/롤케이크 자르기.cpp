#include <bits/stdc++.h>

using namespace std;

int freq[2][10'005];
set<int> kind[2];

int solution(vector<int> topping) {
  int answer = 0;
  int n = topping.size();
  // set과(종류의 수) 빈도수 배열(추가 및 제거)과 포인터(구간 나누기)로 풀어보자
  freq[0][topping[0]] += 1;
  kind[0].insert(topping[0]);
  for (int i = 1; i < n; ++i) {
    if (freq[1][topping[i]] == 0) kind[1].insert(topping[i]);
    freq[1][topping[i]] += 1;
  }

  answer += (kind[0].size() == kind[1].size());

  for (int i = 1; i < n - 1; ++i) {
    // 철수는 추가
    if (freq[0][topping[i]] == 0) kind[0].insert(topping[i]);
    freq[0][topping[i]] += 1;
    // 동생은 삭제
    freq[1][topping[i]] -= 1;
    if (freq[1][topping[i]] == 0) kind[1].erase(topping[i]);
    answer += (kind[0].size() == kind[1].size());
  }
  return answer;
}