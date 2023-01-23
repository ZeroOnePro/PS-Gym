#include <bits/stdc++.h>

using namespace std;

#define RANGE 1000000

int n;
int arr[RANGE + 2];
int freq[RANGE * 2 + 2];

void counting_sort(void) {
  int st = RANGE + 1, en = RANGE * -1 - 1;
  for (int i = 0; i < n; ++i) {
    st = min(arr[i], st);
    en = max(arr[i], en);
    freq[arr[i] + RANGE] += 1;
  }
  for (int i = st; i <= en; ++i) {
    for (int j = 0; j < freq[i + RANGE]; ++j) {
      cout << i << '\n';
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  counting_sort();
  return 0;
}