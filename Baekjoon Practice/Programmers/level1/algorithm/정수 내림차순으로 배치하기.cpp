#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

long long solution(long long n) {
  long long answer = 0;
  string str = to_string(n);
  sort(str.begin(), str.end(), [&str](char a, char b) { return a > b; });
  answer = stoll(str);
  return answer;
}