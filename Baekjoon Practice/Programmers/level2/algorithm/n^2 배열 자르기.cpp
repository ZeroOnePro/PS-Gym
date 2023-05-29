#include <bits/stdc++.h>

#define fastio \
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

vector<int> solution(int n, long long left, long long right) {
  fastio;

  vector<int> answer;
  for (long long i = left; i <= right; i++) {
    long long j = floor(i / n) - i % n;
    j = j < 0 ? 0 : j;
    answer.push_back(i % n + 1 + j);
  }

  return answer;
}