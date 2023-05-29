#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Stu_info {
  string name;
  int kor;
  int eng;
  int math;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<Stu_info> stu(n);
  string name;
  int k, e, m;
  for (int i = 0; i < n; ++i) {
    cin >> name >> k >> e >> m;
    stu[i].name = name;
    stu[i].kor = k;
    stu[i].eng = e;
    stu[i].math = m;
  }
  sort(stu.begin(), stu.end(), [&stu](Stu_info a, Stu_info b) {
    if (a.kor == b.kor) {
      if (a.eng == b.eng) {
        if (a.math == b.math) {
          return a.name < b.name;
        }
        return a.math > b.math;
      }
      return a.eng < b.eng;
    }
    return a.kor > b.kor;
  });
  for (Stu_info s : stu) {
    cout << s.name << '\n';
  }
  return 0;
}