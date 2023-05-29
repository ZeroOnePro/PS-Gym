#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
  int answer = 0;
  col -= 1;
  row_begin -= 1;
  row_end -= 1;
  sort(data.begin(), data.end(), [&](vector<int> a, vector<int> b) {
    if (a[col] == b[col]) return a[0] > b[0];
    return a[col] < b[col];
  });
  vector<int> s;
  int sum = 0;
  for (int i = row_begin; i <= row_end; ++i) {
    sum = 0;
    for (int j = 0; j < data[i].size(); ++j) sum += data[i][j] % (i + 1);
    s.push_back(sum);
  }
  answer = s[0];
  for (int i = 1; i < s.size(); ++i) answer ^= s[i];
  return answer;
}