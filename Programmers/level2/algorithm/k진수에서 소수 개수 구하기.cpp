#include <bits/stdc++.h>

using namespace std;

/*
36이라는 수를 소수판별할 때 우리는 2,4,6,9,18로 나눠떨어지는 것을 알기 때문에
소수가 아닌 것을 알지만 2~6까지만 순회를 해봐도 36이라는 숫자는 앞서 언급한
5개의 숫자로 나눠떨어지는 것을 알 수 있습니다. 그 이유는 i가 2일 때 18과
짝지어지고 4는 9 그리고 6은 6과 짝지어지기 때문입니다. 따라서 n이라는 숫자를
소수판별할 때 2~n의 제곱근까지만 판별해도 소수판별이 가능합니다
*/

typedef long long ll;

const int range = 1e6 + 5;

bool is_prime(ll n) {
  if (n <= 1) return false;
  for (ll i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}

string transform(int n, int k) {
  string result = "";
  while (n != 0) {
    result += to_string(n % k);
    n /= k;
  }
  reverse(result.begin(), result.end());
  return result;
}

int solution(int n, int k) {
  int answer = 0;
  string s = transform(n, k);
  int len = s.length();
  int cur = 0;
  while (cur < len) {
    string tmp = "";
    while (cur < len && s[cur] != '0') {
      tmp += s[cur];
      cur += 1;
    }
    while (cur < len && s[cur] == '0') cur += 1;
    if (!tmp.empty()) answer += is_prime(stoll(tmp));
  }
  return answer;
}