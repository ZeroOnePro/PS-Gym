#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
  vector<int> answer;
  int div = s / n;
  if (div > 0) {
    for (int i = 0; i < n; ++i) answer.push_back(div);
    int mod = s % n, cur = n - 1;
    while (mod != 0) {
      answer[cur--] += 1;
      mod -= 1;
    }
  } else
    answer.push_back(-1);
  return answer;
}