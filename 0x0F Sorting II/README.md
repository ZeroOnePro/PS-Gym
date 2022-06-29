# 0x0F 정렬 II

<!--ts-->

- [0x0F 정렬 II](#0x0f-정렬-ii)
  - [0x00 Counting Sort](#0x00-counting-sort)
  - [0x01 Radix Sort](#0x01-radix-sort)
  - [0x02 STL sort](#0x02-stl-sort)
  - [0x03 정렬의 응용](#0x03-정렬의-응용)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 6월 29일 수요일 15시 58분 02초 KST -->

<!--te-->

## 0x00 Counting Sort

- 원소의 빈도 수를 이용하여 정렬하는 방법
- 메모리 제한으로 인해 원소의 최대값과 최소값 차이, 즉 원소의 범위가 작을 때만 시도해볼 수 있다
  - 대략적으로 수의 범위가 1000만 이내여야 쓸 수 있음
- 시간복잡도
  - 수의 범위가 K개
  - 원소의 수 N개
  - 합사건이므로 O(N + K)
- 구현

  ```cpp
  #define RANGE 1000000

  int n;
  int arr[RANGE + 2];
  int freq[RANGE * 2 + 2];

  void counting_sort(void) {
    int st = RANGE + 1, en = RANGE * -1 - 1;
    for (int i = 0; i < n; ++i) {
      st = min(arr[i], st);
      en = max(arr[i], en);
      freq[arr[i] + RANGE] += 1;
    }
    for (int i = st; i <= en; ++i) {
      for (int j = 0; j < freq[i + RANGE]; ++j) {
        cout << i << '\n';
      }
    }
  }
  ```

## 0x01 Radix Sort

- 원소의 자리수를 이용하여 정렬하는 방법, 카운팅 소트의 응용 버전
- 421 < 502가 왜 참인가?

  ![1](https://user-images.githubusercontent.com/48282185/176375433-7cfa5330-a250-467e-8d37-825affea5425.png)

  - 더 큰 자릿수에서 502의 자릿수가 421의 자릿수보다 큰 경우가 먼저 생겼기 때문
  - 이렇기 때문에 오름차순 기수 정렬에서 언젠가는 502가 421보다 크게 된다

- 진행 과정

  - 1의 자리를 기준으로 정렬된 단계
  - 1의 자리가 같은 수들 끼리는 처음 순서가 유지

    ![2](https://user-images.githubusercontent.com/48282185/176375428-3c091529-ea55-4b92-9818-a2035f73b9a0.png)

  - 10의 자리를 기준으로 정렬된 단계

    ![3](https://user-images.githubusercontent.com/48282185/176375422-003d12f6-d967-46b7-8519-9cb8d21aec0a.png)

  - 100의 자리를 기준으로 정렬된 단계

    ![4](https://user-images.githubusercontent.com/48282185/176375413-2bc0eedb-0cc1-45fc-9c0a-cdafbf61d9c5.png)

- 시간복잡도
  - 자릿수의 최대 개수가 D라 할 때, D번에 걸쳐서 카운팅 소트를 하는 과정과 동일하기에 원소의 개수를 K라 할 때 → O(D \* (N + K)), k는 보통 무시할 정도로 작으므로 O(DN)
- 코딩테스트에서 기수 정렬을 구현을 할 일이 아예 없을 것이지만 그래도 구현은 보고가자

  - 각 원소를 자리수에 맞는 리스트에 넣는 단계에서 만약 모든 원소의 자리수가 같다면 리스트의 한 원소로 쏠리게 되므로 공간의 낭비가 심하게 발생하기에 동적 리스트를 사용한다.
  - 예시로 백만개의 원소의 백의 자리가 1로 모두 동일할 때 백의 자리 정렬 단계에서 백만개의 원소가 다 리스트 1 인덱스로 쏠림
  - 정수의 거듭제곱 계산할 때 pow함수 쓰지마라(실수형이라 오차 발생할 수 있음)

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;

  int n = 15;
  int arr[1000001] = {12, 421, 46, 674, 103, 502, 7, 100, 21, 545, 722, 227, 62, 91, 240};

  // 1, 10, 100의 자리에 대해서 진행, 수가 최대 3자리수가 아닐 경우 d를 조절해야 함
  int d = 3;
  // p10[i] = 10의 i승
  int p10[3];

  // x의 10^a 자리의 값을 반환하는 함수
  int digitNum(int x, int a){
    return (x / p10[a]) % 10;
  }

  vector<int> l[10]; // 자리수 리스트
  int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    p10[0] = 1;
    for(int i = 1; i < d; i++) p10[i] = p10[i-1] * 10;

    for(int i = 0; i < d; i++){
      for(int j = 0; j < 10; j++) l[j].clear();
      // 각 수를 list에 대입
      for(int j = 0; j < n; j++)
        l[digitNum(arr[j], i)].push_back(arr[j]);
      // 0번 리스트부터 차례로 다시 arr에 넣어 재배열
      int aidx = 0;
      for(int j = 0; j < 10; j++){
        for(auto x : l[j]) arr[aidx++] = x;
      }
    }
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
  }
  ```

- Comparison Sort, Non-comparison Sort
  - 머지, 퀵, 버블, 삽입, 선택 정렬은 원소들 간에 크기를 비교하는 과정이 있었음
  - 카운팅, 라딕스 정렬은 원소들 간에 크기를 비교하는 과정이 없음

## 0x02 STL sort

- 퀵소트 기반으로 O(NlogN)이 보장되게 일정 깊이이상 깊어지면 힙소트로 대체된다(introspective sort)
  - introspective는 모니터링한다는 의미를 담고있어 깊이를 모니터링 한다? 정도로 생각하면 될 듯
- stable sort가 아니다, 만약 stable sort가 필요한 상황이 오면 stable_sort()를 활용하자
- 여러가지 속성이 존재하는 데이터들은 pair나 tuple을 사용하여 정렬하자, 원소의 순서대로 정렬 기준이 된다는 점 참고
- 비교함수를 지정해 줄 수 있다

  - 5로 나눈 나머지가 높은 순서로 정렬하는 예시

  ![5](https://user-images.githubusercontent.com/48282185/176375385-3058d217-37d1-45f9-85fb-0e334c93c9a0.png)

  - 주의 사항
    - 비교 함수는 두 값이 같을 때(혹은 우선순위가 같을 때) false를 반환 → sort 런타임에러 발생할 수 있음
    - 비교 함수의 인자로 STL 혹은 클래스 객체를 전달시 reference를 사용

- gcc에 정의된 sort 소스 코드

  [gcc/stl_algo.h at b93ae1a01bbad59ee77b7c84f4743a730138ba87 · gcc-mirror/gcc](https://github.com/gcc-mirror/gcc/blob/b93ae1a01bbad59ee77b7c84f4743a730138ba87/libstdc%2B%2B-v3/include/bits/stl_algo.h#L1934)

## 0x03 정렬의 응용

- 정렬을 이용해서 시간복잡도를 개선할 수 있는 문제들
- 11652 카드 문제

  - $2^{-62}$ ~ $2^{62}$ 범위를 가진 카드에서 제일 많이 등장하는 카드를 찾는 문제
  - 빈도수 배열로 해결하려하면 메모리 제한 초과 날 것이다
  - 빈도수 배열 없이 해결하려하면 O($N^2$)으로 풀어야하는데 이 역시 시간초과가 날 것이다
  - map이나 이진 검색 트리로 해결할 수는 있겠지만, 이 단계에서는 모른다고 가정
  - 시간 복잡도 O(NlogN)
  - 정렬을 하게 되면 같은 원소들 끼리는 인접하기 때문에 중복을 제거할 수도 있음

  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + sizeof(arr) / 8);
    long long cur = arr[0], answer = (1 << 62) * -1 - 1;
    int max_freq = 0, cnt = 0, i = 0;
    while (i < n) {
      while (cur == arr[i]) {
        cnt += 1;
        i += 1;
      }
      if (max_freq < cnt) {
        max_freq = cnt;
        answer = arr[i - 1];
      }
      cnt = 0;
      cur = arr[i];
    }
    cout << answer << '\n';
    return 0;
  }
  ```

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
