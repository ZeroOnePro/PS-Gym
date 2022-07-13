# 0x14 투 포인터

<!--ts-->

- [0x14 투 포인터](#0x14-투-포인터)
  - [0x00 알고리즘 설명](#0x00-알고리즘-설명)
  - [0x01 연습 문제 1 - 수 고르기](#0x01-연습-문제-1---수-고르기)
  - [0x02 연습 문제 2 - 부분합](#0x02-연습-문제-2---부분합)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 7월 13일 수요일 22시 43분 15초 KST -->

<!--te-->

## 0x00 알고리즘 설명

- 배열에서 이중 for문으로 O($N^2$)에 처리되는 작업을 두 개의 포인터의 움직임으로 O(N)에 해결하는 알고리즘
- 이중 for문으로 O($N^2$)에 처리되는 작업 중 i가 0일 때 만들어진 정보가 i=1일 때 활용되는 경우 사용한다
- 이분탐색 문제를 투포인터로 해결할 수 있고, 투포인터 문제를 이분탐색으로 해결할 수 있는 경우가 자주 있다

## 0x01 연습 문제 1 - 수 고르기

- 이분탐색에서 했던 세 수의 합 문제랑 비슷하다
- 이 문제를 이분탐색으로 푼다면 x + M에 대하여 lower_bound로 나오는 수가 답이됨
- 직관적으로 떠오르는 이중 for문 풀이에서 투 포인터로 어떻게 발전해 나가는지 보자

  ```cpp
  for(int i=0; i<n; ++i){
   for(int j=i j<n; ++j){
    if(a[j] - a[i] >= m) ans = min(ans, a[j] - a[i]);
   }
  }
  ```

  - a를 정렬하고 나서 어떤 특징이 있는지 관찰해보자
  - 관찰 1 - i가 증가함에 따라 a[j] - a[i] ≥ m을 만족하는 최초의 지점 j 또한 증가한다(정렬이 되었음)

    ![1](https://user-images.githubusercontent.com/48282185/178748426-3f895d0d-75dc-4462-b483-d3d18599924b.png)

  - 관찰 2 - 각 i에 대해 a[j] - a[i] ≥ m을 만족하는 최초의 지점 j를 찾은 이후에는 a[j+1], a[j+2], …를 확인할 필요가 없다
  - 이 관찰을 바탕으로 투 포인터로 변환해보자
    - 스텝 1 - 두 개의 포인터 st와 en을 둔다
    - 스텝 2 - st는 이중 for문 풀이에서 i의 역할을, en은 j의 역할을 한다, 둘 다 초기값을 0으로 설정한다
    - 스텝 3 - en - st ≥ m이 될 때까지 en을 이동시킨다 찾고나서 min값을 갱신될 필요가 있다면 갱신한다, 그리고 이후로는 더 살펴볼 필요가 없으므로(관찰 2) 다음 스텝으로 넘어간다
    - 다음 후보를 찾기위해 st를 한 칸 이동한다 그리고 다시 스텝 3을 반복한다, en을 0으로 초기화할 필요가 없는 이유는 관찰 1에서 봤듯이 st가 점점 커질 수록 en도 커져야하는데 정렬되있는 상태라 st보다 en이 앞에 있는 경우는 어색하다
  - 투 포인터 구현의 애로사항은 인덱스 실수가 잦다는 점이다

## 0x02 연습 문제 2 - 부분합

- 이거 역시 누적합에 대한 이분탐색으로 풀이가능
- 내가 풀어본 풀이는 아래와 같고, 질문을 남겼고 맞게 풀었다고 답해주셨다
  - 누적합 배열(acc)을 하나 만들고 채운다
  - 구간[i,j]의 부분합은 acc[j] - acc[i-1]이므로 결국에는 누적합 배열에서 이분탐색으로 찾아야하는 대상
  - sum[j]을 target으로 두고, target - acc[i-1] >= s, target >= s + acc[i-1]로 acc[i-1]을 우변으로 보낸다
  - lower_bound(acc, acc+n, s + acc[i-1])으로 찾아주면 끝

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s;
  cin >> n >> s;
  int seq[n], acc[n];
  for (int i = 0; i < n; ++i) cin >> seq[i];
  acc[0] = seq[0];
  for (int i = 1; i < n; ++i) acc[i] = acc[i - 1] + seq[i];
  int bound_len = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int tmp_len =
        lower_bound(acc, acc + n, s + (i == 0 ? 0 : acc[i - 1])) - acc;
    if (tmp_len >= n) continue;
    bound_len = min(bound_len, tmp_len - i + 1);
  }
  cout << (bound_len == INT_MAX ? 0 : bound_len);
  return 0;
}
```

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
