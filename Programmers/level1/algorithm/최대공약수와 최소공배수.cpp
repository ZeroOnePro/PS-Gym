#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, int m) {
  vector<int> answer;
  int lcm = n * m;
  while (m != 0) {
    int r = n % m;
    n = m;
    m = r;
  }
  answer.push_back(n);
  answer.push_back(lcm /= n);
  return answer;
}