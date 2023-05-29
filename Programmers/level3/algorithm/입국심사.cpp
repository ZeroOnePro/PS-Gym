#include <bits/stdc++.h>

using namespace std;

// k분에 모든 사람의 심사가 가능한가? parametric search?

typedef long long ll;

bool possible(ll x, int n, vector<int>& times) {
  ll sum = 0;
  for (int i = 0; i < times.size(); ++i) sum += x / times[i];
  return sum >= n;
}

long long solution(int n, vector<int> times) {
  long long answer = 0;
  // int * int 하면 int가 돼서 오버플로날 수 있음, 기본적인걸 놓치다니..
  ll st = 0, en = (ll)*max_element(times.begin(), times.end()) * (ll)n;
  while (st <= en) {
    ll mid = (st + en) / 2;
    if (possible(mid, n, times))
      en = mid - 1;
    else
      st = mid + 1;
  }
  answer = st;
  return answer;
}