#include <string>
#include <vector>

using namespace std;

bool check[1000001];

int solution(int n) {
  int answer = 0;
  check[0] = check[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!check[i]) {
      // i*i는 오버플로우 우려때문에 2*i로 하는게 안전
      for (int j = 2 * i; j <= n; j += i) {
        check[j] = true;
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (!check[i]) {
      answer += 1;
    }
  }
  return answer;
}