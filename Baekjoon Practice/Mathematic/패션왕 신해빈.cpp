#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    map<string, int> types;
    while (n--) {
      string name, type;
      // 이름은 유니크 => 키
      cin >> name >> type;
      // 같은 타입이므로 다른이름의 같은 옷종류 빈도수 배열
      types[type] += 1;
    }
    map<string, int>::iterator it = types.begin();
    ll ans = 1;
    for (; it != types.end(); ++it) {
      ans *= (ll)(it->second + 1);
    }
    cout << ans - 1 << '\n';
  }

  return 0;
}