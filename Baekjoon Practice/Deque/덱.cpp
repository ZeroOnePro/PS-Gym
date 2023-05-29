#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define MAX 10000
using namespace std;

// 한쪽에 push 하고 같은 쪽에서 pop 하면, 스택처럼 사용할 수 있다.
// 한쪽에 push 하고 반대쪽에서 pop 하면, 큐처럼 사용할 수 있다.
// 인덱싱을 서큘러 큐처럼 모듈러연산으로 구현한다. => 순환하잖아

class Deque {
private:
  int front;
  int back;
  int deque[MAX];

public:
  Deque() {
    front = 0;
    back = 0;
    memset(deque, 0, MAX - 1);
  }

public:
  bool empty() {
    if (front == back) {
      return true;
    } else {
      return false;
    }
  }
  void push_front(int element) {
    deque[front] = element;
    front = (front - 1 + MAX) % MAX;
  }
  void push_back(int element) {
    back = (back + 1) % MAX;
    deque[back] = element;
  }
  int pop_front() {
    if (empty()) {
      return -1;
    } else {
      front = (front + 1) % MAX;
      int element = deque[front];
      return element;
    }
  }
  int pop_back() {
    if (empty()) {
      return -1;
    } else {
      int element = deque[back];
      back = (back - 1 + MAX) % MAX;
      return element;
    }
  }
  int size() { return (back - front + MAX) % MAX; }
  int f() {
    if (empty()) {
      return -1;
    }
    return deque[(front + 1) % MAX];
  }
  int b() {
    if (empty()) {
      return -1;
    }
    return deque[back];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  Deque d = Deque();
  while (n--) {
    string command;
    cin >> command;
    if (command == "push_back") {
      int element;
      cin >> element;
      d.push_back(element);
    } else if (command == "push_front") {
      int element;
      cin >> element;
      d.push_front(element);
    } else if (command == "pop_front") {
      cout << d.pop_front() << '\n';
    } else if (command == "pop_back") {
      cout << d.pop_back() << '\n';
    } else if (command == "empty") {
      cout << d.empty() << '\n';
    } else if (command == "front") {
      cout << d.f() << '\n';
    } else if (command == "back") {
      cout << d.b() << '\n';
    } else if (command == "size") {
      cout << d.size() << '\n';
    } else {
      continue;
    }
  }
  return 0;
}
