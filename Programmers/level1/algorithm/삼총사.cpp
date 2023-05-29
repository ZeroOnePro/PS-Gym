#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> number) {
  int answer = 0;
  sort(number.begin(), number.end());
  int n = number.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int target = -number[i] - number[j];
      answer += upper_bound(number.begin() + j + 1, number.end(), target) -
                lower_bound(number.begin() + j + 1, number.end(), target);
    }
  }
  return answer;
}