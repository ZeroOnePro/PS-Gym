#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Nation {
  int num;
  int gold;
  int silver;
  int bronze;
  int rank;
} Nation;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, target;
  cin >> n >> target;
  vector<Nation> nations(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> nations[i].num >> nations[i].gold >> nations[i].silver >>
        nations[i].bronze;
  }
  sort(nations.begin(), nations.end(),
       [&nations](Nation &a,
                  Nation &b) mutable { // 인자도 포인터로 받아야 값이 바뀐다.
         if (a.gold == b.gold) {
           if (a.silver == b.silver) {
             if (a.bronze == b.bronze) {
               return a.bronze > b.bronze;
             }
             return a.bronze > b.bronze;
           }
           return a.silver > b.silver;
         }
         return a.gold > b.gold;
       });
  int rank = 1;
  int cursor = 1;
  int index = 0;
  nations[0].rank = rank;
  for (int i = 1; i < n; i++) {
    if (nations[i - 1].gold == nations[i].gold) {
      if (nations[i - 1].silver == nations[i].silver) {
        if (nations[i - 1].bronze == nations[i].bronze) {
          nations[i].rank = rank;
          cursor += 1; // 건너뛰는 것
          // 1등, 공동2등 2명, 4등, ... 이렇게 가네 3등이 없네
          //  문제를 잘 읽자
          continue;
        }
      }
    }
    rank += cursor;
    nations[i].rank = rank;
    cursor = 1;
  }
  for (int i = 0; i < n; ++i) {
    if (nations[i].num == target) {
      cout << nations[i].rank << '\n';
      break;
    }
  }
  return 0;
}