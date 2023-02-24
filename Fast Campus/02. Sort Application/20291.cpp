#include <bits/stdc++.h>

using namespace std;

vector<string> parse(string origin, string delimiter) {
  vector<string> token;
  size_t pos = 0;
  while ((pos = origin.find(delimiter)) != string::npos) {
    token.push_back(origin.substr(0, pos));
    origin.erase(0, pos + delimiter.length());
  }
  token.push_back(origin);
  return token;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  // . 앞에 문자열 날리고 이후 확장자만 저장해서 정렬해서 몇 개 있는지 세기
  // 확실히 hash쓰면 매우 간편하긴 하겠다
  vector<string> file;
  for (int i = 0; i < n; ++i) {
    string file_name;
    cin >> file_name;
    size_t pos = file_name.find('.');
    file.push_back(file_name.substr(pos + 1));
  }
  sort(file.begin(), file.end());
  string cur = file[0];
  int cnt = 0;
  file.push_back("proxy");
  for (int i = 0; i < file.size(); ++i) {
    if (cur == file[i])
      cnt += 1;
    else {
      cout << file[i - 1] << ' ' << cnt << '\n';
      cur = file[i];
      cnt = 1;
    }
  }
  return 0;
}