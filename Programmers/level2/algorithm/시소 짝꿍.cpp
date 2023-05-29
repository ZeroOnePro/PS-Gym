#include <bits/stdc++.h>

// 최소 공배수, 최대 공약수
// 존재 검사는 빈도수로 할 수 있다
// 중복 안되게!!

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
  int c;
  while (b != 0) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

long long solution(vector<int> weights) {
  long long answer = 0;
  map<ll, ll> freq;
  for (int w : weights) freq[w] += 1;
  for (auto [w, f] : freq) {
    answer += (f - 1) * f / 2L;
    for (auto [cw, cf] : freq) {
      if (cw == w) continue;
      int llcm = lcm(cw, w);
      if (llcm == cw) llcm *= 2;
      if (llcm / min(cw, w) <= 4) answer += f * cf;
    }
    freq.erase(w);
  }
  return answer;
}