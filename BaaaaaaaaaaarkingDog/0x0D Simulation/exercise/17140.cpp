#include <bits/stdc++.h>

using namespace std;

#define pi2 pair<int, int>

const int range = 101;

int R, C, k, r = 3, c = 3, t = 0;
int a[range + 5][range + 5];

void input() {
  cin >> R >> C >> k;
  R--;
  C--;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) cin >> a[i][j];
}

// 행 정렬
// 1. 행을 기준으로 숫자 몇개 나오는지 센다 => (빈도수, 숫자)로 pair로 저장
// 2. 정렬
// 3. 정렬 결과 만들기
// 4. 다음 operation을 위해 만들어진 최대 열의 길이 갱신
void row_sort() {
  priority_queue<int> pq;
  for (int i = 0; i < r; ++i) {
    vector<pi2> row;
    vector<int> freq(range + 5);
    for (int j = 0; j < c; ++j) freq[a[i][j]] += 1;
    for (int j = 1; j < range; ++j)
      if (freq[j] != 0) row.push_back({freq[j], j});
    sort(row.begin(), row.end());
    for (int j = 0; j < c; ++j) a[i][j] = 0;
    int idx = 0;
    for (auto [f, e] : row) {
      a[i][idx++] = e;
      a[i][idx++] = f;
    }
    pq.push(idx);
  }
  c = max(c, pq.top());
}

// 열 정렬
// 1. 열을 기준으로 숫자 몇개 나오는지 센다 => (빈도수, 숫자)로 pair로 저장
// 2. 정렬
// 3. 정렬 결과 만들기
// 4. 다음 operation을 위해 만들어진 최대 행의 길이 갱신
void col_sort() {
  priority_queue<int> pq;
  for (int i = 0; i < c; ++i) {
    vector<pi2> col;
    vector<int> freq(range + 5);
    for (int j = 0; j < r; ++j) freq[a[j][i]] += 1;
    for (int j = 1; j < range; ++j)
      if (freq[j] != 0) col.push_back({freq[j], j});
    sort(col.begin(), col.end());
    for (int j = 0; j < r; ++j) a[j][i] = 0;
    int idx = 0;
    for (auto [f, e] : col) {
      a[idx++][i] = e;
      a[idx++][i] = f;
    }
    pq.push(idx);
  }
  r = max(r, pq.top());
}

void print() {
  cout << '\n';
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) cout << a[i][j] << ' ';
    cout << '\n';
  }
}

// 매 초마다 어떤 연산이 적용될지 판단하고, 연산 적용해주기
// freq 초기화 해야함
void operate() {
  while (a[R][C] != k) {
    if (r >= c)
      row_sort();
    else
      col_sort();
    t += 1;
    if (t > 100) {
      cout << -1;
      return;
    }
  }
  cout << t;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  operate();
  return 0;
}