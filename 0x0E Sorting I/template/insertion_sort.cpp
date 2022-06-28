#include <bits/stdc++.h>

using namespace std;

int arr[10];

void insertion_sort(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
      else
        break;
    }
  }
}

void print_result(int n) {
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << ' ';
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int len = sizeof(arr) / 4;
  for (int i = 10; i >= 1; --i) arr[10 - i] = i;
  insertion_sort(len);
  print_result(len);
  return 0;
}