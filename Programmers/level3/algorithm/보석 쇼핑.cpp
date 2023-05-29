#include <bits/stdc++.h>

// 투 포인터

using namespace std;

typedef tuple<int, int, int> ti3;

map<string, int> freq;

vector<int> solution(vector<string> gems) {
  vector<int> answer;
  priority_queue<ti3, vector<ti3>, greater<ti3>> pq;
  for (string name : gems) freq[name] = 0;
  if (freq.size() == 1) return {1, 1};
  int st = 0, en = 0, cnt = 0, len = gems.size();
  while (en <= len - 1) {
    while (en < len && cnt != freq.size()) {
      freq[gems[en]] += 1;
      if (freq[gems[en]] == 1) cnt += 1;
      en += 1;
    }
    while (st < len && cnt == freq.size()) {
      freq[gems[st]] -= 1;
      if (freq[gems[st]] == 0) cnt -= 1;
      st += 1;
    }
    if (cnt + 1 == freq.size()) pq.push({en - st, st, en});
  }
  auto [l, s, e] = pq.top();
  answer = {s, e};
  return answer;
}