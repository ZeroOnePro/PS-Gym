# 0x0C 백트래킹

<!--ts-->

- [0x0C 백트래킹](#0x0c-백트래킹)
  - [0x00 알고리즘 설명](#0x00-알고리즘-설명)
  - [0x01 연습 문제 1 - N과 M](#0x01-연습-문제-1---n과-m)
  - [0x02 연습 문제 2 - N-Queen](#0x02-연습-문제-2---n-queen)
  - [0x03 연습 문제 3 - 부분수열의 합](#0x03-연습-문제-3---부분수열의-합)
  - [0x04 STL next_permutation](#0x04-stl-next_permutation)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 6월 28일 화요일 12시 58분 21초 KST -->

<!--te-->

## 0x00 알고리즘 설명

- 현재 상태에서 가능한 모든 후보군을 따라 들어가며 탐색하는 알고리즘
- 상태공간트리에서 가능한 모든 경우를 나열해본 뒤, 정답과 어긋난다면 다른 경우 탐색
- 실생활 예시 - 오목
- 상당한 구현력 필요
- 재귀 특성상 틀린 부분 찾기 어렵다
- 모든 경우의 수를 구하는 문제에서(완전 탐색), 정답을 만족하는 경우들은 모든 경우의 수 중 일부이고, 정답을 만족시키지 못하는 조건을 미리 알고, 불가능한 케이스는 사전 차단한다

## 0x01 연습 문제 1 - N과 M

- N = 4, M = 3인 경우 상태 공간 트리의 일부

![1](https://user-images.githubusercontent.com/48282185/172656658-109ce648-8539-4b07-a4d7-b04c44db8fc7.png)

- 정답코드이기도 하지만 전형적인 백트래킹의 형태

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, m;
int seq[10];
bool is_used[10];

// 현재 x개까지의 수를 선택 후 seq[x](= x+1 번째 수)를 정하는 함수
void make_seq(int cur){
 if(cur == m){
  for(int i = 0; i < m; ++i) cout << seq[i] << ' ';
  cout << '\n';
 }

 /* 핵심 로직 */
 for(int elem = 1; elem <= n; ++elem){
  if (is_used[elem]) continue;
  is_used[elem] = true;
  seq[cur] = elem;
  make_seq(cur + 1);
  is_used[elem] = false;
 }
 /**********/
}

int main(void){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 cin >> n >> m;
 make_seq(0);
}
```

## 0x02 연습 문제 2 - N-Queen

- N x N 체스판에 퀸 N개를 서로 공격하지 못하게 하는 경우의 수

![2](https://user-images.githubusercontent.com/48282185/172656651-63855b9b-7fc1-43cf-ae3c-d16675fa1dc4.png)

![3](https://user-images.githubusercontent.com/48282185/172656646-3e5620a9-0364-4ca2-810f-33b752f4f926.png)

- 행을 늘려가면서 배치를 한다
  - 다시말하면, 다음 퀸을 놓을 때 행은 검사할 필요가 없다.
- 열과 대각선에 대해 검사한다.
  - 열은 같은 좌표인지 확인
  - 일반적인 좌표평면과는 달리 2차원 행렬을 좌표평면으로 표현하면 180도 뒤집혀있다, 즉 일반적인 좌표 평면은 y축의 방향이 아래에서 위로 되있고, 행은 위에서 아래로 향한다.
  - 그리고 좌표을 2차원 배열로 표현하면 x가 행을, y가 열을 의미하기에 90도 대칭이다.
  - `/` 대각선에 놓여있는지 체크(일반적인 좌표평면에서 180도 대칭)
    - 일차함수 x = -y + k 상에 놓여있는 두 좌표인지 확인하는 것과 같은 문제
    - x + y의 값이 같으면 같은 대각선 상에 위치
  - `\` 대각선에 놓여있는지 체크(일반적인 좌표평면에서 180도 대칭)
    - 일차함수 x = y + k 상에 놓여있는 두 좌표인지 확인하는 것과 같은 문제
    - x - y의 값이 같으면 같은 대각선 상에 위치(음수가 나올 수 있기때문에 절대값 취해줘야 한다)
- 각 퀸을 놓고 이 퀸의 공격 가능 좌표를 기억해둔다면, 다음 행 퀸을 놓을 때 이 공격 가능 좌표에 놓여있는지 안 놓여있는지 확인할 수 있다.

```cpp
#include <bits/stdc++.h>

using namespace std;

bool is_used[3][40];  // 1차원 열, 2차원 오른 대각, 3차원 왼 대각

int cnt;
int n;

void n_queen(int row) { // row번째 행에 말을 배치할 예정임
  if (row == n) { // N개를 놓는데 성공했다면
    cnt++;
    return;
  }
  for (int i = 0; i < n; i++) { // (row, i)에 퀸을 놓을 예정
  // column이나 대각선 중에 공격 가능 좌표가 있을 경우
  // x(row) + y(i)
  // x(row) - y(i) + n-1(인덱스 음수 방지, 모듈러와 비슷한 맥락, abs써도 무방)
   if (is_used[0][col] or is_used[1][row + col] or
        is_used[2][row - col + n - 1])
      continue;
    is_used[0][col] = true;
    is_used[1][row + col] = true;
    is_used[2][row - col + n - 1] = true;

    n_queen(row + 1);

    is_used[0][col] = false;
    is_used[1][row + col] = false;
    is_used[2][row - col + n - 1] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  n_queen(0);
  cout << cnt;
}
```

- 불가능함을 알아채고 다음 상태를 탐색하지 않는 것을 가지치기(pruning)라고 한다. 가지치기가 많을수록 시간복잡도를 예측하기 힘들다 이때는 직접 구현한 뒤 가장 시간이 오래 걸릴법한 케이스로 테스트해보고 시간초과 나는지 확인해보자(제일 큰 N)
- 컴파일러의 release 모드

  [참고 블로그](https://itisguide.tistory.com/4)

  - 컴퍼일러가 어셈블리어로 변환 시 코드 최적화를 하는 것
  - 최적화하여 속도는 빨라지지만 소스 코드와 생성된 명령 간의 관계가 복잡해지므로 중단점이 제대로 안찍히는 등의 문제가 발생하여 디버깅이 복잡해진다는 단점이 존재한다.
  - PS할 때 로컬에서 시간 잴 필요가 있는 경우 릴리즈모드로 컴파일하자

## 0x03 연습 문제 3 - 부분수열의 합

- -2, 5, 3

![4](https://user-images.githubusercontent.com/48282185/172656617-e507af10-56dc-43c5-a22c-60d9782e63d5.png)

- 원소가 n개인 집합에서 부분집합의 개수는 $2^n$(n개에 대해 뽑고 안뽑고)
- 모든 부분집합에 대해 합이 S와 일치하는지 확인
- 매 순간 수를 더할지 더하지 않을지 결정하는 방식으로 구현한다.

```cpp
#include <bits/stdc++.h>

using namespace std;

int n, s;
int sequence[30];
int cnt;

// cur은 수열 인덱스
void check_sum(int cur, int total){
  if(cur == n){
    if(total == s) cnt++;
    return;
  }
  check_sum(cur+1, total); // 더하지 않는 경우
  check_sum(cur+1, total + sequence[cur]); // 더하는 경우
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for(int i = 0; i < n; i++)
    cin >> sequence[i];
  check_sum(0, 0);
  if(s == 0) cnt--; // s가 0일 때 공집합 제외(문제 조건에 크기가 양수인 부분수열이라 했으므로)
  cout << cnt;
}
```

## 0x04 STL next_permutation

```cpp
// 순열
int seq[3] = {1, 2, 3};

do{
 for(int elem : seq) cout << seq[i] << ' ';
 cout << '\n';
}while(next_permutation(seq.begin(), seq.end()));

// 2개를 순서없이 뽑는 순열(조합)
int seq[4] = {0, 0, 1, 1};

// 원소 중복이 가능하므로 이처럼 구현가능하다
do{
 for(int i=0; i<4; ++i) if(seq[i]) cout << i + 1;
 cout << '\n';
}while(next_permutation(seq.begin(), seq.end()));
```

- 순열과 조합이 필요할 때 사용할 수 있음
- 정렬이되있어야함
- 원소 중복 가능

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
>
> [BaaarkingDog](https://www.youtube.com/c/BaaarkingDog)
