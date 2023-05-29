#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;
  priority_queue<int, vector<int>, less<int>> pq;
  queue<pair<int, bool>> q;
  int index = 0;
  for (int p : priorities) {
    pq.push(p);
    if (index == location)
      q.push(make_pair(p, true));
    else
      q.push(make_pair(p, false));
    index += 1;
  }
  int cnt = 0;
  while (1) {
    if (q.front().first == pq.top()) {
      if (q.front().second == true) {
        break;
      } else {
        q.pop();
        pq.pop();
      }
      cnt += 1;
    } else {
      q.push(q.front());
      q.pop();
    }
  }
  answer = ++cnt;
  return answer;
}