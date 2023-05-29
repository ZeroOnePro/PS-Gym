#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> generateDivisors(int number) {
  int cursor = 1;
  vector<int> divisors;
  while (cursor <= number) {
    if (!(number % cursor)) {
      divisors.push_back(cursor);
    }
    cursor += 1;
  }
  return divisors;
}
// brown + yellow = w * h
// yellow의 약수가 가로 세로 길이 후보
// 노란색으로 사각형 만든 뒤, 갈색으로 덮어씌울 수 있는지 본다.
// 노란색으로 만든 사각형의 가로길이 * 2 (위 아래) + 세로길이 * 2 (왼 오른) +
// 4(꼭지) == 총 격자 개수 w >= h (문제 조건)
vector<int> solution(int brown, int yellow) {
  vector<int> answer;
  vector<int> divisors = generateDivisors(yellow);
  int numOfDivisors = divisors.size(), width = 0, height = 0;
  for (int iter = 0; iter <= numOfDivisors / 2; ++iter) {
    width = divisors[numOfDivisors - iter - 1];
    height = divisors[iter];
    if (width * 2 + height * 2 + 4 == brown && width >= height) break;
  }
  answer.push_back(width + 2);
  answer.push_back(height + 2);
  return answer;
}