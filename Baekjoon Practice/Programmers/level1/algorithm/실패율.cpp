#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;
  // 빈도수 배열을 이용하여, 각 스테이지에 몇명이 있는지 알아보자
  // 거꾸로 탐색하여 각 스테이지를 거쳐간 인원을 누적시킨다.
  // n+1이 있다.
  vector<int> peoples(N + 2, 0);
  vector<int> take_out(N + 2, 0);
  for (int i : stages) {
    peoples[i] += 1;
    take_out[i] += 1;
  }
  int sum = peoples[N + 1];
  for (int i = N; i >= 1; --i) {
    take_out[i] += sum;
    sum = take_out[i];
  }
  vector<pair<int, double>> failure_rate(N + 1, make_pair(0, 0.0));
  for (int i = 1; i <= N; ++i) {
    if (take_out[i] == 0) {
      failure_rate[i].first = i;
      failure_rate[i].second = 0;
      continue;
    }
    failure_rate[i].second = peoples[i] / (double)take_out[i];
    failure_rate[i].first = i;
  }
  sort(failure_rate.begin(), failure_rate.end(),
       [&failure_rate](pair<int, double> a, pair<int, double> b) {
         if (a.second != b.second)
           return a.second > b.second;
         else
           return a.first < b.first;
       });
  for (pair<int, double> a : failure_rate) {
    if (a.first == 0) continue;
    answer.push_back(a.first);
  }
  return answer;
}