#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int s : scoville) {
    pq.push(s);
  }
  while (!pq.empty() && pq.top() < K) {
    int first = pq.top();
    pq.pop();
    int second = 0;
    if (!pq.empty()) {
      second = pq.top();
      pq.pop();
    } else {
      answer = -1;
      break;
    }
    int new_scoville = first + 2 * second;
    pq.push(new_scoville);
    answer += 1;
  }

  return answer;
}