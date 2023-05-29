#include <bits/stdc++.h>

using namespace std;

// 슬라이딩 윈도우
map<string, int> dis;
map<string, int> w;

bool check() {
  int cnt = 0;
  for (auto [product, n] : w)
    if (dis[product] >= n) cnt += 1;
  return cnt == w.size();
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;
  int ws = 10;
  for (int i = 0; i < want.size(); ++i) w[want[i]] = number[i];
  for (int i = 0; i < ws; ++i) dis[discount[i]] += 1;
  if (check()) answer += 1;
  for (int st = 1; st <= discount.size() - ws; ++st) {
    int en = st + 9;
    dis[discount[st - 1]] -= 1;
    dis[discount[en]] += 1;
    if (check()) answer += 1;
  }
  return answer;
}