#include <bits/stdc++.h>

using namespace std;

int a[8];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a[8] = {0, 2, 0, 2, 8, 8, 0, 16};
  bool merged[8] = {
      false,
  };
  for (int i = 1; i < 8; ++i) {
    if (a[i] != 0) {
      int start = i;
      int elem = a[i];
      while (start >= 1 && a[start - 1] == 0) {
        a[start--] = 0;
      }
      a[start] = elem;
      if (start >= 1 && !merged[start - 1] && elem == a[start - 1]) {
        a[start - 1] *= 2;
        merged[start - 1] = true;
        a[start] = 0;
      }
    }
  }
  for (int elem : a) {
    cout << elem << ' ';
  }
  return 0;
}