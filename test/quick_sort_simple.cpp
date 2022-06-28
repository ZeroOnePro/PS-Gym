#include <bits/stdc++.h>

using namespace std;

int arr[8] = {6, -8, 1, 12, 8, 3, 7, -7};

void quick_sort() {
  int tmp[8] = {};
  int pivot = arr[0];
  int index = 0;
  for (int i = 1; i < 8; ++i) {
    if (arr[i] <= pivot) tmp[index++] = arr[i];
  }
  tmp[index++] = pivot;
  for (int i = 1; i < 8; ++i) {
    if (arr[i] > pivot) tmp[index++] = arr[i];
  }
  copy(tmp, tmp + 8, arr);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  quick_sort();
  for (int i = 0; i < 8; ++i) cout << arr[i] << ' ';
  return 0;
}