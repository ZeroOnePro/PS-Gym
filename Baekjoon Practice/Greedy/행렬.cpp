#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, cnt = 0;
vector<string> a;
vector<string> b;

void flip(int x, int y) {
  cnt++;
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (a[x + i][y + j] == '0')
        a[x + i][y + j] = '1';
      else
        a[x + i][y + j] = '0';
    }
  }
}

int main() {

  int i, j;
  bool flag = true;
  string s;

  cin >> n >> m;

  for (i = 0; i < n; i++) {
    cin >> s;
    a.push_back(s);
  }

  for (i = 0; i < n; i++) {
    cin >> s;
    b.push_back(s);
  }

  for (i = 0; i < n - 2; i++) {
    for (j = 0; j < m - 2; j++) {
      if (a[i][j] != b[i][j]) {
        flip(i, j);
      }
    }
  }

  for (i = 0; i < n; i++) {
    if (flag) {
      for (j = 0; j < m; j++) {
        if (a[i][j] != b[i][j]) {
          cout << "-1\n";
          flag = false;
          break;
        }
      }
    }
  }

  if (flag)
    cout << cnt << endl;

  return 0;
}