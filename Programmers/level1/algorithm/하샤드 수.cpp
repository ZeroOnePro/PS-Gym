#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
  bool answer = true;
  int sum = 0;
  int tmp = x;
  while (tmp > 0) {
    sum += tmp % 10;
    tmp /= 10;
  }
  x % sum ? answer = false : answer = true;
  return answer;
}