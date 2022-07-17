#include <bits/stdc++.h>

using namespace std;

int heap[100005];
int sz = 0;  // heap에 들어있는 원소의 수

void push(int x) {
  heap[++sz] = x;
  // 제자리 찾아주기
  int cur = sz;
  while (cur != 1) {
    int parent = cur / 2;
    if (heap[parent] <= heap[cur]) break;
    swap(heap[parent], heap[cur]);
    cur = parent;
  }
  return;
}

void pop(void) {
  if (sz == 0) {
    cout << 0 << '\n';
    return;
  }
  cout << heap[1] << '\n';
  heap[1] = heap[sz--];
  int cur = 1;
  // 왼쪽 자식의 인덱스가 size보다 크면 leaf
  while (2 * cur <= sz) {
    int lc = 2 * cur, rc = 2 * cur + 1;
    int min_child = rc <= sz && heap[rc] < heap[lc] ? rc : lc;
    if (heap[cur] <= heap[min_child]) break;
    swap(heap[cur], heap[min_child]);
    cur = min_child;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, query;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> query;
    if (query == 0)
      pop();
    else
      push(query);
  }
  return 0;
}