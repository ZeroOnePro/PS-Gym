# 문제풀이 (6549 안 풀음)

## 총평

+ 스택 수열, 탑문제를 통해 스택에 무작정 쌓는게 아닌 중간에 빼기도 해가면서 푸는 접근법을 배울 수 있었다.
+ 그 이후에 문제들은 문제 풀이 접근법 자체는 맞았으나 디테일에서 비효율적으로 구현하거나 틀렸다.
+ 스택 카테고리에 매우 약함을 느꼈고, 6549같은 플레티넘문제는 아직 나에게는 버겁다 생각하여 생략하고 넘어가기로 결정(펌핑 후에 강해져서 돌아오자)
+ 스택은 여기까지 하고 강해져서 돌아오자
+ 강해지는 방법은 dfs, bfs까지 진도를 나간 후 그 이후에 프로그래머스나 백준에서 스택카테고리만 골라 실버 ~ 골드 수준 문제 10개정도만 더 풀어보자

## 1874 스택 수열 (틀림)

### 내 풀이

1. 입력되는 수열을 역순으로 배열에 넣는다.
2. 예시의 `4 3 6 8 7 5 2 1`을 예로 들어보면 `1 2 5 7 8 6 3 4`이 된다.
3. 왼쪽부터 차례대로 읽어가면서 top과 비교 후 top보다 크다면 입력이 될 때까지 그 구간의 모든 정수를 스택에 넣되 top과 current가 연속된 수가 아닐 경우 그 사이의 수는 빠져야한다.
4. pop되면 스택 수열의 원소가 된다. 
5. top보다 작은 것을 만나면 current < top까지 pop
 + 1 (top 0, current 1) // 1
 + 2 (top 1, current 2) // 1 2
 + 5 (top 2, current 5) current와 top사이에 3, 4가 빠졌으므로 current - top - 1만큼 pop이 일어나야함 2번 current - top > 1
 + 7 (top 5, current 7) 6 pop 한 번 // 1 2 5 7
 + 8 (top 7, current 8) // 1 2 5 7 8
 + 6 (top 8, current 6) // 1 2 5
 + 3 (top 5, current 3) // 1 2 
 + 4 (top 2, current 4) // -

```plaintext
+ 1
+ 2
+ 3
+ 4 
- 4 // 4
- 3 // 4 3
+ 5
+ 6
- 6 // 4 3 6
+ 7
+ 8
- // 4 3 6 8
- // 4 3 6 8 7
- // 4 3 6 8 7 5
- // 4 3 6 8 7 5 2
- // 4 3 6 8 7 5 2 1
```

4 3 5 2 1

// 1 2 3 4 // -

// 1 2 3 // 4

// 1 2 3 4 5 // -

// 1 // 4 5 4 3 2

// 4 5 4 3 2 1 // 수열에 중복 요소 있어서 불가능한 케이스

```cpp
ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string solution;
  stack<int> s;
  stack<int> seq;
  int top = 0; // 스택에 들어간 마지막 수
  vector<int> freq(n + 1);

  for (int i = 0; i < n; ++i)
  {
    int input;
    cin >> input;
    s.push(input);
  }
  int current = s.top();
  while (!s.empty())
  {
    if (top < current)
    {
      if (current - top == 1)
      {
        solution += "+";
        seq.push(current);
      }
      else
      {
        top = seq.empty() ? top : seq.top();
        seq.push(current);
        int gap = current - top - 1;
        while (gap--)
        {
          solution += "+";
        }
        int interval = current - top;
        while (interval > 1)
        {
          solution += "-";
          interval -= 1;
        }
        for (int i = top + 1; i < current; ++i)
          freq[i] += 1;
        solution += "+";
      }
      if (!s.empty())
        s.pop();
      top = current;
      if (!s.empty())
        current = s.top();
    }
    else
    {
      while (!seq.empty())
      {
        solution += "-";
        freq[seq.top()] += 1;
        seq.pop();
      }
      while (!s.empty())
      {
        s.pop();
      }
    }
  }
  bool possible = true;

  for (int i = 1; i <= n; ++i)
  {
    if (!freq[i])
      possible = false;
  }

  if (possible)
  {
    for (char ch : solution)
    {
      cout << ch << '\n';
    }
  }
  else
  {
    cout << "NO" << '\n';
  }
  return 0;
```

### 정답 풀이 및 코드

```cpp
// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/7a18dc82bd4041aaa59c745f06d4ba60
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<int> S;
  int cnt = 1;
  string ans;
  while (n--) {
    int t;
    cin >> t;
    while (cnt <= t) {
      S.push(cnt++);
      ans += "+\n";
    }
    if (S.top() != t) {
      cout << "NO\n";
      return 0;
    }
    S.pop();
    ans += "-\n";
  }
  cout << ans;
}

/*
현재 처리를 필요로 하는 수는 cnt이다. 
cnt 이상인 값 t가 주어지면 그 값을 pop할 수 있게 cnt가 t가 될 때 까지 push를 해야 한다. 
만약 S.top()과 t가 일치하지 않는다면 올바르지 않은 수열이다.
*/
```

+ pop 되는게 수열의 원소가 된다.
+ t가 수열에 나와야하므로 t가 나오기 위한 스택의 환경을 만들어준다고 생각
+ t가 나와아하므로 t를 pop할 수 있게 cnt가 t가 될 때 까지 push해줘야함 
+ cnt는 t를 만들기위한 용도일 뿐 신경쓰지 않아도 되는 값이다.
+ 스택에 쌓이는 순서는 오름차순이어야한다.

// 4 3 6 8 7 5 2 1

+ cnt: 1 t: 4
  - stack: 1 2 3
  - cnt를 4까지 올리고 4는 pop해야한다.
  - 스택 수열: 4

+ cnt: 5 t: 3
  + stack: 1 2
  + 3을 pop하면 된다.
  + 스택 수열: 4 3

+ cnt: 5 t: 6
  + stack 1 2 5
  + cnt를 6까지 올리고, 6을 pop한다.
  + 스택 수열: 4 3 6

+ cnt: 7 t: 8
  + stack 1 2 5 7
  + cnt를 8까지 올리고, 8을 pop한다.
  + 스택 수열: 4 3 6 8

+ cnt: 9 t: 7
  + stack: 1 2 5 
  + 7을 pop하면 된다.
  + 스택 수열: 4 3 6 8 7

+ cnt: 9 t: 5
  + stack: 1 2
  + 5를 pop하면 된다.
  + 스택 수열: 4 3 6 8 7 5

+ cnt: 9 t: 2
  + stack 1
  + 2를 pop하면 된다.
  + 스택 수열: 4 3 6 8 7 5 2

+ cnt: 9 t: 1
  + stack: empty
  + 1을 pop하면 된다.
  + 스택 수열: 4 3 6 8 7 5 2 1


### 틀린 이유 분석
    
  1. 수열을 만드는 것에 집중 pop되는 것이 수열의 순서임을 인지하고 해당 원소가 나오기 pop되기 위해 스택이 어떻게 구성되있어야 했는지를 시뮬레이션함
  2. 접근 자체를 아예 잘못한 것 같다... pop되는 것이 스택 수열의 순서임을 캐치하지 못했다.
  3. 너무 테스트 케이스에 얽매여서 general하지 못하게 짠 것 같다.

### 교훈
  1. 문제를 완전히 이해했다고 생각할 때 코딩에 돌입한다.
  2. 여러케이스에서 시험해보면 좋으나 백준은 그게 좀 어렵기 때문에 질문탭에 들어가서 반례케이스를 살펴본다.


## 2493 탑 (틀림)

처음에는 입력 순서대로 스택으로 쌓고 하나씩 빼가며 top과 비교하며 current가 top보다 작거나 같다면 신호를 받을 수 있는 것이므로 top의 index를 저장해놓고
반대로 current가 top보다 크다면 받을 수 없는 것이므로 체크해놓고 계속 pop해나가면서 current보다 큰 원소가 나오는지 검사한다. => O(N^2)이고 20분동안 생각해봤던 것 같다.
50만 입력 크기에 N^2 시간 복잡도가 나오므로 틀릴 것을 직감하고있었으나 마땅한 수가 떠오르지 않았고, 풀면서 굳이 스택없이도 수열로도 가능한 걸 왜 스택으로 하고 있나 싶기도 했다.
거꾸로도 스택에 쌓아봤는데 이걸 가지고 어떻게 해야하나 감이 잘 안오고 머리에서 생각하기를 거부했다. 이 나쁜 버릇은 고쳐야한다.
스택 알고리즘 부족함의 밑천이 드러나는 것 같다. `스택은 연습 문제 이외에도 좀 더 풀어봐야겠다.`
그래서 정답코드를 보기로 결정했다.

```cpp
// Authored by : twinkite
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/44465623025e452bba5feb80b0b0e60e
#include <bits/stdc++.h>
using namespace std;

int N;
stack<pair<int,int>> tower;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;  
  tower.push({100000001, 0});
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;
    while (tower.top().first < height)
      tower.pop();    
    cout << tower.top().second << " ";
    tower.push({height, i});      
  }
}
```

직관적으로는 이해가 잘 안가서 스텝 몇가지만 해보겠다.

최대 입력 값보다 높은 높이인 관념적인 0번째 탑 first를 푸시하며 시작한다.

+ 6 9 5 7 4
  + 6입력 first > height이므로 stack의 원소가 pop되지 않는다.
  + pair형태로 탑의 인덱스를 저장하고 처음은 0을 출력하게 된다.
  + {6,1}이 푸시된다.

  + 9입력 first < height이므로 stack의 원소가 pop된다.
  + 6의 index 0 출력
  + {9,2}가 푸시된다.

  + ...

+ first < height는 왼쪽 탑의 크기보다 오른쪽 탑의 크기가 크다는 이야기 이므로 신호를 받을 수 있는 즉 first >= height인 first를 찾을 때까지 pop을 해야한다.
+ 이게 되는 이유는 뒤에 first보다 크거나 같은 탑이 나와도 위에서 찾은 first >= height인 first는 스택에서 pop되지 않으므로 걸리게 되고 first와 찾은 탑 사이는 first보다 작으므로 무조건 찾은 탑이 신호를 받을 수 있음이 보장된다.
+ 반면 first > height는 왼쪽 탑의 크기가 오른쪽 탑의 크기보다 크다는 이야기이므로 신호를 받을 수 있고, 신호를 받을 수 있는탑이 나왔으므로 조사하지 않아도 된다.


## 6198 옥상 정원 꾸미기(비효율적으로 풀었음 다시 풀어보기)

+ 문제를 읽고나니, 저번에 풀었던 탑 문제와 유사하다고 생각되었다.
+ 그래서 입력 순서대로 스택에 쌓아보게 되었다.
+ 조건은 탑 문제와 동일하게 stack의 top이 height(=입력)보다 작거나 같은 경우 pop을 하지 않는다.(top에서 몇 개까지 볼 수 있는지 저장)
+ stack의 top이 height보다 큰 경우, stack이 비지 않을 때까지 pop을 시킨다.(top보다 높이가 높은게 나와 이제 더 이상 볼 수 없으니 뺀다.)
+ pop된 것이 볼 수 있는 건물의 개수라고 생각한다.(top의 관점에서)
+ 10 3 7 4 12의 경우를 살펴보자
+ 10이 쌓인다.
+ 3은 10보다 스택에 쌓인다.
+ 7은 3보다 크므로 3이 스택에서 빠진다.
+ 4는 7보다 작으므로 스택에 쌓인다.
+ 12는 4보다 크므로 4가 스택에서 빠진다.
+ 12는 7보다 크므로 7이 스택에서 빠진다.
+ 12는 10보다 크므로 10이 스택에서 빠진다.
+ 2는 12보다 작으므로 스택에 쌓인다.

+ 여기까지 생각을 하고 각 빌딩에서 관찰할 수 있는 옥상의 갯수는 어떻게 구할 까를 고민해보자.
+ pop이 된다는 것은 더 이상 기억하지 않아도 된다.
+ 10의 경우 12가 들어올 때빠지게 되는데 10에서 볼 수 있는 것들은 3, 4, 7이고 10은 4, 7과 함께빠지게 된다.
+ 10의 경우에는 3도 관찰가능하므로 10의 경우에 수에 3이 들어가 있어야한다.(경우 1)
+ 그래서 처음에는 빠질 때 빠진 빌딩의 순서를 배열 같은데다가 기억해놓고, 어떤 빌딩이 빠질 때 이미 빠진(=배열에 저장되있는) 인덱스보다 빠지는 빌딩의 인덱스가 작은 경우 카운트에 포함시키려 했다
+ 생각해보니 너무 비효율 적인 거 같았다. 물론 스택에 쌓는거 n, 1~n의 요소들 순차 검사라 시간복잡도는 O(n)이지만, 이것보다 확실히 효율적인게 있을 거같다는 강한 느낌이 들어 다시 생각해보니,
+ 각 빌딩이 스택에 들어갈 때 pop과정을 거친 후 스택의 사이즈를 누적 시켜놓으면 되겠다는 생각이 들었다.
+ 각 빌딩이 스택에 들어가기 전에 size를 관찰한다.
+ 10 들어감, size = 0, total = 0
+ 3 들어감, size = 1, total = 1
+ 7 들어감, size = 1, total = 2
+ 4 들어감, size = 2, total = 4
+ 12 들어감, size = 0, total = 4
+ 2 들어감, size = 1, total = 5
+ 이렇게 하니 total에 이미 누적이 되있으므로 배열에 저장할 필요가 없어졌다.
+ 결론적으로 접근법은 맞았으나 배열에 저장하는 헛짓거리를 했다.
+ 이문제도 다시 풀어보자


## 3015 오아시스 재결합(틀림)

+ 이 문제는 스택쌓는 순서나 언제 pop처리를 해야하는지도 맞고, count세는 로직도 유사했다.
+ pop 할 때 ans += 1를 하여 들어오는 input기준으로 그 이전에 스택에 저장되있던 값들과 쌍을 이루어, 가능한 쌍 수를 증가시켰다.
+ 스택이 비지 않았을 때 ans += 1을 하여 top > input인 것을 pop 과정을 거치지 않는 input에 대해 (top, input)의 쌍을 만들어 주었다.
+ 문제는 내가 input과 top이 같을 때를 고려하지 못했고, 그 결과 정답보다 1 작은 수가 나왔다.
+ 조금만 더 생각해봤으면 풀었을 것 같은데, 조급한 성격 탓에 풀이가 잘못된 것으로 의심하고 정답을 보게되었다.
+ 생각해보는 시간을 늘려야겠다.(기존 30분 => 1시간)

## 전략

+ 중간에 pop되는게 그 이전에 쌓였던 top을 이용한 계산에 포함되야 한다면, pair형태의 구조를 스택에 쌓는 것을 고려해보자
