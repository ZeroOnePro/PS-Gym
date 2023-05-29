#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B) {
  int answer = 0;
  priority_queue<int, vector<int>, greater<int>> pq1;
  priority_queue<int, vector<int>, less<int>> pq2;
  for (int i : A) {
    pq1.push(i);
  }
  for (int i : B) {
    pq2.push(i);
  }
  while (!pq1.empty()) {
    answer += pq1.top() * pq2.top();
    pq1.pop();
    pq2.pop();
  }
  return answer;
}