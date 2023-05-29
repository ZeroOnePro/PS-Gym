#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
  long long answer = 0;
  if (sqrt(n) == ceil(sqrt(n))) {
    long double tmp = n / (long long)sqrt(n);
    tmp += 1;
    answer = tmp * tmp;
  } else {
    answer = -1;
  }
  return answer;
}