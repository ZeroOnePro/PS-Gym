#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(long long n) {
  vector<int> answer;
  queue<int> q;
  while (n != 0) {
    q.push(n % 10);
    n /= 10;
  }
  while (!q.empty()) {
    answer.push_back(q.front());
    q.pop();
  }
  return answer;
}