#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
  int answer = 0;
  sort(citations.begin(), citations.end(),
       [](auto a, auto b) { return a > b; });
  for (int i = 0; i < citations.size(); ++i)
    if (i + 1 <= citations[i]) answer = max(i + 1, answer);
  return answer;
}