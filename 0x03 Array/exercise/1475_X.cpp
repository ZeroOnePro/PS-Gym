#include <bits/stdc++.h>

using namespace std;

// 틀렸던 로직: 최대등장 번호가 6또는 9일 때 /2하고 6또는 9의 등장 회수만큼
// 더해줬음 => 아예 틀린 논리

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int roomNum;
  vector<int> freq(10);
  cin >> roomNum;
  while (roomNum > 0) {
    int digit = roomNum % 10;
    // 6이 나왔을 경우 6또는 9에 쓰일 수 있기때문에, 등장 시 6 또는 9의 등장
    // 횟수를 비교 후 적은곳에 활용되어야 한다. / 9의 경우도 마찬가지 66999를
    // 생각해보자 왼쪽에서 오른쪽으로 6은 6에쓰인다. 6이 나왔는데 freq[6] >=
    // freq[9]이므로 9를 이용하여 6을 만든다 freq[9] += 1 9가 나옴 9는 9에
    // 쓰인다. 9가 나왔는데 freq[6] <= freq[9]이므로 6을 이용하여 9를 만든다
    // freq[6] += 1 9가 나옴 9는 9에 쓰임 총 3세트 필요
    if (digit == 6 || digit == 9) {
      if (freq[9] >= freq[6])
        freq[6] += 1;
      else
        freq[9] += 1;
    } else {
      freq[digit] += 1;
    }
    roomNum /= 10;
  }
  cout << *max_element(freq.begin(), freq.end()) << '\n';
  return 0;
}