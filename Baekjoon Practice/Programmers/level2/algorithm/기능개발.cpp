#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  queue<int> q;
  // 앞의 것이 끝나기 전까지 못한다 => 큐
  for (int i = 0; i < progresses.size(); ++i) {
    int cnt = 0;
    while (progresses[i] < 100) {
      progresses[i] += speeds[i];
      cnt += 1;
    }
    q.push(cnt);  // 각 작업에서 걸리는 날짜 계산
  }
  // 날짜들을 큐에 집어넣고, top부터 꺼내는데, 만약 꺼내다가 top보다 큰 수가
  // 발견되면, 멈추고 정답에 집어넣는다.
  int days = q.front();
  q.pop();
  int deploy = 1;
  while (!q.empty()) {
    if (q.front() <= days) {
      deploy += 1;
      q.pop();
    } else {
      answer.push_back(deploy);
      days = q.front();
      q.pop();
      deploy = 1;
    }
  }
  answer.push_back(deploy);
  return answer;
}