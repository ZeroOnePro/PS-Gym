#include <string>
#include <vector>

using namespace std;

string base_3(int n) {
  string s;
  while (n != 0) {
    int r = n % 3;
    s += to_string(r);
    n /= 3;
  }
  return s;
}

int base_10(string s) {
  int base = 1;
  int result = 0;
  for (int i = s.length() - 1; i >= 0; --i) {
    result += base * (s[i] - '0');
    base *= 3;
  }
  return result;
}

int solution(int n) {
  int answer = 0;
  answer = base_10(base_3(n));
  return answer;
}