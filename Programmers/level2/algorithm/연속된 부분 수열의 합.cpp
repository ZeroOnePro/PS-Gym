#include <bits/stdc++.h>

using namespace std;

// 구간합 + 투 포인터

vector<int> solution(vector<int> sequence, int k) {
  vector<int> answer;
  vector<int> acc;
  int st = 0, en = 0, len = sequence.size(), mn_len = 1'000'001;
  acc.push_back(0);
  for (int i = 0; i < len; ++i) acc.push_back(sequence[i] + acc[i]);
  while (st <= en && en <= len) {
    int sum = acc[en] - acc[st];
    if (sum == k) {
      int new_len = en - st - 1;
      if (mn_len > new_len) {
        answer = {st, en - 1};
        mn_len = new_len;
      }
    }
    if (sum < k)
      en += 1;
    else
      st += 1;
  }
  return answer;
}