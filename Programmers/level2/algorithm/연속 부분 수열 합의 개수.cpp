#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
  int answer = 0, sz = elements.size();
  set<int> sums;
  for (int st = 0; st < sz; ++st)
    for (int len = 1; len <= sz; ++len) {
      int sum = 0;
      for (int j = st; j < st + len; ++j) {
        sum += elements[j % sz];
      }
      sums.insert(sum);
    }
  answer = sums.size();
  return answer;
}