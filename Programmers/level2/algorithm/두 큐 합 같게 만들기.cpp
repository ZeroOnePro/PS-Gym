#include <bits/stdc++.h>

using namespace std;

/*
    계속 핑퐁되는 게 있나??
    [1, 2, 4], [3, 2, 4]
    최대 이동횟수는 queue 사이즈 x 4
    queue1, queue2가 다시 자기 자신으로 돌아오기까지 필요한 이동횟수의 최대
*/

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
  int answer = 0;
  queue<ll> q1, q2;
  int mx_move = queue1.size() * 4;
  ll sum1 = 0, sum2 = 0, tot = 0, mid = 0;
  for (int i : queue1) {
    q1.push((ll)i);
    sum1 += (ll)i;
  }
  for (int i : queue2) {
    q2.push((ll)i);
    sum2 += (ll)i;
  }
  tot = sum1 + sum2;
  mid = tot / 2;
  if (tot & 1) {
    answer = -1;
    return answer;
  }
  while (sum1 != sum2) {
    while (!q1.empty() && sum1 > mid) {
      ll elem = q1.front();
      q1.pop();
      sum1 -= elem;
      sum2 += elem;
      if (sum1 == mid) {
        answer += 1;
        break;
      }
      q2.push(elem);
      answer += 1;
    }
    while (!q2.empty() && sum2 > mid) {
      ll elem = q2.front();
      sum2 -= elem;
      sum1 += elem;
      if (sum2 == mid) {
        answer += 1;
        break;
      }
      q2.pop();
      q1.push(elem);
      answer += 1;
    }
    if (q1.empty() || q2.empty() || answer > mx_move) {
      answer = -1;
      break;
    }
  }
  return answer;
}