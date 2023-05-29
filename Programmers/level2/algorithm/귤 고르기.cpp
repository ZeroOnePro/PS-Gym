#include <bits/stdc++.h>

using namespace std;

// k개를 다 채울 수 있어함
// 빈도수 많은거 부터 포함시키고, 다 채우면 K개됬는지 확인
// 부족하면 다음으로 빈도수 많은거 포함시킨다
// 왜냐면 서로 다른게 최소가 되야하므로
// 빈도수 저장해놓고, 우선순위 큐에 담자, 우선순위 = 빈도수 큰 순

// 다른 사람 풀이는 정렬을 이용한 게 많았다

const int range = 10'000'001;

int freq[range];

int solution(int k, vector<int> tangerine) {
  int answer = 0;
  int n = tangerine.size();
  int mx = 0, mn = range;
  int cnt = k;
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    if (mn > tangerine[i]) mn = tangerine[i];
    if (mx < tangerine[i]) mx = tangerine[i];
    freq[tangerine[i]] += 1;
  }
  for (int i = mn; i <= mx; ++i) pq.push(freq[i]);
  while (!pq.empty()) {
    cnt -= pq.top();
    answer += 1;
    if (cnt <= 0) break;
    pq.pop();
  }
  return answer;
}