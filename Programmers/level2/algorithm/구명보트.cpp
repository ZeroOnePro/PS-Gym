#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
  int answer = 0;
  sort(people.begin(), people.end());
  // two pointer + greedy
  // 탐욕 기준: 현재 선택 옵션 중 최대 + 최소가 제한을 초과하는지 보기
  int l = 0, r = people.size() - 1;
  while (l <= r) {
    if (people[l] + people[r] <= limit) {
      answer += 1;
      l += 1;
      r -= 1;
    } else {
      answer += 1;
      r -= 1;
    }
  }
  return answer;
}