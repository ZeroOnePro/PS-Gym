#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  // n번째 회의로 시작하면 총 몇개의 회의가 생기는지 체크
  // 탐욕기준: 시작시간이 같은 경우 (끝시각 - 시작시각)이 제일 짧은 것, 이전
  // 회의와 다음회의의 간격이 가장 짧은 것 안되는 것: 다음 회의시작시간이
  // 이전회의의 끝시각보다 작은 경우 다음 회의만 골라놓고, i loop에서 그
  // 골라놓은 회의의 차례가 오면 누적을 시키면 되잖아? 다음 회의만 골라놓으면 됨
  // 시간초과 -> 다른 방법 필요
  // 회의가 끝나는 시간을 정렬하고 같다면, 시작시간이 작은 것을 기준으로
  // 정렬하여 회의의 수를 센다. 끝나는 시간을 기준으로 정렬해도 가장 짧은 회의를
  // 찾을 수 있다 왜냐하면 끝나는 시각이 작다는 것은 그만큼 회의가 일찍끝났다는
  // 얘기고, 다음에 진행할 수 있는 회의를 더 많이 넣을 수 있다 그리고 끝나는
  // 시각이 같다면 시작시간이 기준이 되기 때문에
  vector<pair<int, int>> conference(n, make_pair(0, 0));
  for (int i = 0; i < n; ++i) {
    cin >> conference[i].first >> conference[i].second;
  }

  sort(conference.begin(), conference.end(),
       [&conference](pair<int, int> a, pair<int, int> b) {
         if (a.second == b.second) {
           return a.first < b.first;
         }
         return a.second < b.second;
       });
  int max_con = 0;
  int present_con = 0;
  for (int i = 0; i < n; ++i) {
    if (present_con <= conference[i].first) {
      present_con = conference[i].second;
      max_con++;
    }
  }
  cout << max_con << '\n';
  /*
  vector<int> next_con(n, n+1); // i번째 회의의 다음회의의 인덱스를 담는다
  for (int i = 0; i < n; ++i) {
          int min_time = INT_MAX;
          int min_bin = INT_MAX;
          for (int j = 0; j < n; ++j) {
                  if (i == j) continue;
                  if (conference[i].second <= conference[j].first) {
                          if (conference[j].first - conference[i].second <=
  min_bin) { min_bin = conference[j].first - conference[i].second; if
  (conference[j].second - conference[j].first < min_time) { next_con[i] = j;
                                          min_time = conference[j].second -
  conference[j].first;
                                  }
                          }
                  }
          }
  }
  int max_num_of_con = 0;
  for (int i = 0; i < n; ++i) {
          int cursor = next_con[i];
          int count = 0;
          while (cursor != n + 1) {
                  cursor = next_con[cursor];
                  count += 1;
          }
          if (count > max_num_of_con) {
                  max_num_of_con = count;
          }
  }
  cout << max_num_of_con+1 << '\n';
  */
  return 0;
}