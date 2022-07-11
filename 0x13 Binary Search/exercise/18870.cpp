#include <bits/stdc++.h>

using namespace std;

int binary_search(int target, vector<int>& arr) {
  int st = 0;
  int en = arr.size() - 1;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (arr[mid] > target)
      en = mid - 1;
    else if (arr[mid] < target)
      st = mid + 1;
    else
      return mid;
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int arr[n], copied_arr[n];
  vector<int> uniq;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    copied_arr[i] = arr[i];
  }
  sort(copied_arr, copied_arr + n);
  for (int i = 0; i < n; ++i) {
    if (i == 0 or copied_arr[i] != copied_arr[i - 1])
      uniq.push_back(copied_arr[i]);
  }
  for (int i = 0; i < n; ++i) {
    cout << binary_search(arr[i], uniq) << ' ';
    // lower_bound로도 뽑아낼 수 있지만, 연습 차원에서 다시 한 번 구현해봤음
    // cout << lower_bound(uniq.begin(), uniq.end(), arr[i]) - uniq.begin() << '
    // ';
  }
  return 0;
}