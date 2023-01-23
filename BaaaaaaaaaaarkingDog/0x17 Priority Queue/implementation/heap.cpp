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

int top() { return heap[1]; }

void pop() {
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

void print_status() {
  for (int i = 1; i <= sz; ++i) cout << heap[i] << ' ';
  cout << '\n';
}

void test() {
  push(10);
  push(2);
  push(5);
  push(9);                // {10, 2, 5, 9}
  cout << top() << '\n';  // 2
  pop();                  // {10, 5, 9}
  pop();                  // {10, 9}
  cout << top() << '\n';  // 9
  push(5);
  push(15);               // {10, 9, 5, 15}
  cout << top() << '\n';  // 5
  pop();                  // {10, 9, 15}
  cout << top() << '\n';  // 9
}

int main() { test(); }