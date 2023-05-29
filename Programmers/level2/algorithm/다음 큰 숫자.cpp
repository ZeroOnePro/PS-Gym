#include <string>
#include <vector>

using namespace std;

int CountOne(int n) {
  int count = 0;
  while (n != 0) {
    int r = n % 2;
    if (r) count += 1;
    n /= 2;
  }
  return count;
}

int solution(int n) {
  int answer = 0;
  for (int i = n + 1;; i += 1) {
    if (CountOne(i) == CountOne(n)) {
      answer = i;
      break;
    }
  }
  return answer;
}