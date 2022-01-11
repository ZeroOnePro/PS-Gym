#include <bits/stdc++.h>

using namespace std;

void parser(const string &origin, vector<int> &tokens, string &delimiter)
{
  // find_first_of: 문자열의 위치를 지정위치부터 탐색하여 찾은 위치 리턴
  // find_first_not_of: 주어진 문자열을 제외한 나머지 문자를 지정위치부터 탐색하여 찾은 위치 리턴
  string::size_type subStrCursor = origin.find_first_not_of(delimiter, 0);
  string::size_type tokenCursor = origin.find_first_of(delimiter, subStrCursor);

  while (string::npos != tokenCursor || string::npos != subStrCursor)
  {
    tokens.push_back(stoi(origin.substr(subStrCursor, tokenCursor - subStrCursor)));
    subStrCursor = origin.find_first_not_of(delimiter, tokenCursor);
    tokenCursor = origin.find_first_of(delimiter, subStrCursor);
  }
}

// 입력값을 고려하지 못하여 시간초과가 계속 났었는데, QnA를 보고 흉내를 내야한다고 힌트를 얻었다. 애시당초에 입력 크기 고려 안 한 내 잘못도 있다.

// https://www.acmicpc.net/board/view/25456

//  R 명령이 들어온다고 진짜로 배열의 모든 원소를 뒤집으면 절대로 안 됩니다. N개의 원소의 순서를 정말로 바꾸면 당연히 그 원소 수만큼 시간이 걸리고, 그걸 최대 10만 번 수행해야 하니 테스트 케이스 1개만으로도 100억번의 연산이 수행됩니다.
//  R 명령의 핵심은 실제로 원소를 뒤집지 않고도 뒤집힌 것과 같은 효과를 내도록 구현하는 것입니다. C++의 std::reverse(), Python의 a[::-1] 역시 사용해서는 안 됩니다.
//  D 명령에 대해서 보통 배열의 맨 앞 원소를 무작정 지워서는 안 됩니다.C++ 의 vector::erase(), Java의 ArrayList.remove(), Python의 list.pop() 등으로 배열의 첫 번째 원소를 지울 시, 그 뒤에 있는 모든 원소들을 전부 한 칸씩 앞으로 당겨오게 되므로, 그 시간 역시 원소의 수에 비례하여 소요됩니다.
//  라이브러리 함수는 호출만 하면 N개의 원소를 기적같이 O(1) 에 처리해주는 마법사가 아닙니다.저렇게 원소를 당겨오는 작업 없이도 D의 기능을 구현할 수 있어야 합니다.
//  빈 배열은[] 로 출력해야 합니다.아무것도 출력하지 않거나, error를 출력하거나, 무조건 원소를 하나 출력하고 시작하려고 하면 안 됩니다.
//  배열이 비어있는데 R을 하는 건 에러가 아닙니다.D만 에러입니다.테스트 케이스마다 초기화가 잘 됐는지 확인하세요.그리고 매 케이스마다 개행 문자를 항상 출력하는지 확인하세요.
//  처음 배열의 상태에 대한 문자열의 길이는 최대 400001자입니다. 입력 문자 배열 크기를 잘 설정하세요.처음 배열의 상태로 빈 배열이 주어지는 경우를 조심하세요.수가 무조건 하나 이상 있다고 가정하고 코드를 작성하면 이런 경우를 제대로 처리하지 못할 수 있습니다.
//  조건문 안에 strlen(str)를 절대로 넣지 마세요.strlen은 문자열의 처음부터 널 문자가 나올 때까지 한 글자씩 확인하므로, 반복문을 한 바퀴 돌 때마다 문자열의 길이만큼의 시간이 걸립니다.
//  단순히 R과 D의 개수만 세고 나중에 몰아서 처리하는 건 당연히 안 됩니다.R을 할 때마다 D를 했을 때 지워지는 원소가 달라지기 때문입니다.'
//  배열에 들어있는 수는 최대 100입니다. 무조건 한 글자로 가정하고 구현하면 안 됩니다.참고로, 예제에도 두자리의 수가 하나 등장하지만 어차피 지워지는 원소이기 때문에 한 글자로 가정해도 "예제는" 답이 잘 나올 수 있습니다.예제를 믿지 마세요.

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  while (n--)
  {
    vector<int> tokens;
    deque<int> dq;
    string delimiter = "[],", array, command;
    bool isReverse = false, isError = false;
    int length = 0;
    cin >> command >> length >> array;
    parser(array, tokens, delimiter);
    for (int element : tokens)
    {
      dq.push_back(element);
    }
    for (char c : command)
    {
      if (c == 'R')
        isReverse = !isReverse;
      else
      {
        if (dq.empty())
        {
          isError = true;
          break;
        }
        if (!isReverse)
          dq.pop_front();
        else
          dq.pop_back();
      }
    }
    if (isError)
      cout << "error\n";
    else
    {
      if (isReverse)
        reverse(dq.begin(), dq.end());
      cout << '[';
      for (int i = 0; i < (int)dq.size(); i++)
      {
        cout << dq[i];
        if (i + 1 != (int)dq.size())
          cout << ',';
      }
      cout << "]\n";
    }
  }
  return 0;
}