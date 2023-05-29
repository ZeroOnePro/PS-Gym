#include <string>
#include <vector>

using namespace std;

int gcd_clac(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm_clac(int a, int b) { return a * b / (gcd_clac(a, b)); }

int solution(vector<int> arr) {
  int answer = arr[0];
  for (int i = 1; i < arr.size(); ++i) {
    answer = lcm_clac(answer, arr[i]);
  }
  return answer;
}