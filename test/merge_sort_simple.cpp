#include <bits/stdc++.h>

using namespace std;

int arr1[5] = {-9, 1, 6, 8, 12};
int arr2[4] = {-7, 7, 13, 15};
int merged[9];

void merge_sort() {
  int arr1_cur = 0, arr2_cur = 0;
  int index = 0;
  while (arr1_cur < 5 and arr2_cur < 4) {
    if (arr1[arr1_cur] > arr2[arr2_cur])
      merged[index++] = arr2[arr2_cur++];
    else if (arr1[arr1_cur] < arr2[arr2_cur])
      merged[index++] = arr1[arr1_cur++];
    else
      continue;
  }
  if (arr1_cur < 5)
    for (int i = arr1_cur; i < 5; ++i) merged[index++] = arr1[i];
  if (arr2_cur < 4)
    for (int i = arr2_cur; i < 4; ++i) merged[index++] = arr2[i];
}

void print_result(int n, int *list) {
  for (int i = 0; i < n; ++i) {
    cout << list[i] << ' ';
  }
  cout << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  merge_sort();
  print_result(9, merged);
  return 0;
}