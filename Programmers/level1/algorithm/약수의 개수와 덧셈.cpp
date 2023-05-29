#include <string>
#include <vector>

using namespace std;

bool num_of_divisor(int n) {
  int cnt = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cnt++;
      if (i * i < n) cnt++;
    }
  }
  return cnt & 1;
}

int solution(int left, int right) {
  int answer = 0;
  for (int i = left; i <= right; ++i) {
    if (num_of_divisor(i))
      answer -= i;
    else
      answer += i;
  }
  return answer;
}