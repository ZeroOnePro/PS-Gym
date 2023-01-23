#include <bits/stdc++.h>

using namespace std;

int n = 10;
int arr[10] = {9, 7, 1, 3, 4, 5, 6, 2, 8, 10};
int tmp[10];

// mid = (st+en)/2라고 할 때 arr[st:mid], arr[mid:en]은 이미 정렬이 되어있는
// 상태일 때 arr[st:mid]와 arr[mid:en]을 합친다.
void merge(int st, int en) {
  int mid = (st + en) / 2;
  int l_cur = st;
  int r_cur = mid;
  for (int i = st; i < en; ++i) {
    if (l_cur == mid)
      tmp[i] = arr[r_cur++];
    else if (r_cur == en)
      tmp[i] = arr[l_cur++];
    else if (arr[l_cur] <= arr[r_cur])
      tmp[i] = arr[l_cur++];
    else
      tmp[i] = arr[r_cur++];
  }
  for (int i = st; i < en; i++) arr[i] = tmp[i];
  return;
}

void merge_sort(int st, int en) {
  if (st + 1 == en) return;
  int mid = (st + en) / 2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
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
  merge_sort(0, n);
  print_result(10, arr);
  return 0;
}