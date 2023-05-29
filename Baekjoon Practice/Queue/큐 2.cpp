#include <iostream>
#include <string>

using namespace std;

class Queue {
public:
  int queue[2000000];
  int begin = 0;
  int end = 0;

public:
  bool empty() {
    if (begin == end) {
      return true;
    } else {
      return false;
    }
  }

  void push(int element) {
    queue[end] = element;
    end += 1;
  }

  int pop() {
    if (empty())
      return -1;

    // 리턴을 해버려서 begin이 반영이 안되기 때문에 이렇게 한다
    begin += 1;
    return queue[begin - 1];
  }

  int size() { return end - begin; }

  int front() {
    if (empty())
      return -1;
    else {
      return queue[begin];
    }
  }

  int back() {
    if (empty())
      return -1;
    else {
      return queue[end - 1];
    }
  }
};

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;

  cin >> n;

  Queue q = Queue();

  while (n--) {
    string command;
    cin >> command;
    if (command == "push") {
      int element;
      cin >> element;
      q.push(element);
    } else if (command == "pop") {
      cout << q.pop() << '\n';
    } else if (command == "size") {
      cout << q.size() << '\n';
    } else if (command == "empty") {
      cout << q.empty() << '\n';
    } else if (command == "front") {
      cout << q.front() << '\n';
    } else if (command == "back") {
      cout << q.back() << '\n';
    } else {
      continue;
    }
  }

  return 0;
}
