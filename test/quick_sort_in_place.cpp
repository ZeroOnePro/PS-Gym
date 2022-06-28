#include <bits/stdc++.h>

using namespace std;

int arr[8] = {6, -8, 1, 12, 8, 3, 7, -7};

void quick_sort() {
  int pivot = arr[0];
  int l_cur = 1, r_cur = 7;
  while (l_cur < r_cur) {
    if (arr[l_cur] <= pivot)
      l_cur++;
    else if (arr[r_cur] > pivot)
      r_cur--;
    else if (arr[l_cur] > pivot && arr[r_cur] < pivot) {
      swap(arr[l_cur++], arr[r_cur--]);
    }
  }
  swap(arr[r_cur], arr[0]);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  quick_sort();
  for (int i = 0; i < 8; ++i) cout << arr[i] << ' ';
  return 0;
}