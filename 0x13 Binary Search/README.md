# 0x13 이분탐색

<!--ts-->

- [0x13 이분탐색](#0x13-이분탐색)
  - [0x00 알고리즘 설명](#0x00-알고리즘-설명)
  - [0x01 구현 및 STL](#0x01-구현-및-stl)
  - [0x02 연습 문제 1 - 좌표 압축](#0x02-연습-문제-1---좌표-압축)
  - [0x03 연습 문제 2 - 세 수의 합](#0x03-연습-문제-2---세-수의-합)
  - [0x04 Parametric Search](#0x04-parametric-search)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 7월 12일 화요일 02시 48분 10초 KST -->

<!--te-->

## 0x00 알고리즘 설명

- 정렬되어 있는 배열에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로 확인하는 대신 탐색 범위를 절반으로 줄여가며 찾는 탐색 방법

## 0x01 구현 및 STL

- 구현

  ```cpp
  int a[100005];
  int n;

  bool binary_search(int target) {
    int st = 0;
    int en = n - 1;
    while (st <= en) {
      int mid = (st + en) / 2;
      if (a[mid] < target)
        st = mid + 1;
      else if (a[mid] > target)
        en = mid - 1;
      else
        return true;
    }
    return false;
  }
  ```

- STL

  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>

  using namespace std;

  int main(void){
   vector<int> a = {3, 4, 5, 10, 17, 7};
   sort(a.begin(), a.end());
   int target;
   cin >> target;
   bool find = binary_search(a.begin(), a.end(), target);
   cout << find;
   return 0;
  }
  ```

- 배열에서 특정 원소가 몇 번 등장했는지 빈도수를 세는데 이분탐색이 활용될 수 있다

  - 10816 - 숫자 카드 2

    - 풀어보니 빈도수 배열로 풀어도 통과는 된다.
    - 빈도수 배열로 풀려면 배열대신 vector로 선언해서 풀어야한다, 지역변수는 스택영역에 쌓이는데 이 스택영역의 크기 제한은 보통 1MB ~ 8MB사이이다.(대략 천만) 그래서 문제에서와 같이 2천만이 필요한 경우 segmentfault가 나게 된다. vector는 동적 할당이라 heap영역을 사용하여 이보다는 제한이 덜하다
    - 이분탐색을 활용해서 이문제를 해결하는 다른 아이디어가 있다
    - 정렬된 배열에서 특정 수가 몇 개 중복되는지 확인하기 위해서 그 원소가 등장하는 첫 인덱스와 그 원소가 마지막으로 등장하는 인덱스를 알면 두 인덱스의 차로 몇 개가 중복되는지 알 수 있다
    - 오름 차순을 유지하면서 찾고자 하는 수를 삽입할 수 있는 가장 왼쪽 인덱스와 가장 오른쪽 인덱스를 찾는데, 실제로 삽입하는 것은 아니다. 그 수가 어디서부터 시작해서 어디서 끝나는지 파악하기 위함이다
    - 가장 왼쪽 인덱스는 해당 수가 등장하는 첫번째 인덱스이고 가장 오른쪽 인덱스는 해당 수보다 큰 수가 최초로 등장하는 인덱스이다

      ![1](https://user-images.githubusercontent.com/48282185/178326361-cba10cb8-7f46-471c-8b07-33bb41a7bee7.png)

    - 위 예시에서 순서를 유지하면서 10을 삽입할 수 있는 가장 왼쪽 인덱스는 3이고, 가장 오른쪽 인덱스는 5이다
    - 이런 아이디어를 바탕으로 시작 인덱스를 구해보자. a[mid] > target인 상황에서는 mid가 가장 오른쪽 인덱스가 될 후보가 될 수도 있다 즉, 특정 수가 중복되는 구간의 끝 바로 다음일 가능성이 있기에 en을 mid로 변경한다(삽입한다는 가정 하에 삽입할 수 있는 가장 오른쪽)
    - 10번 인덱스가 있는 이유는 32보다 큰 수가 삽입될 가능성도 있기때문임

      ![2](https://user-images.githubusercontent.com/48282185/178326355-354001e1-ed19-4acf-8261-733aceba6f3f.png)

    - en이 변경되었으니 mid도 변경하여 범위를 줄인다 mid를 (st + en) / 2로 바꿔주면, 이번에는 a[mid] < 10이므로 st를 mid + 1로 바꾼다, 삽입할 수 있는 가장 왼쪽 위치는 무조건 mid보다 크다

      ![3](https://user-images.githubusercontent.com/48282185/178326353-92695096-8a2e-45e3-9501-69b66fd244b1.png)

    - st가 변경되었으니 mid도 변경하여 범위를 줄인다 mid를 (st + end) / 2로 바꿔주면 이번에는 a[mid] = 10이고, 이 위치가 삽일 될 수 있는 가장 왼쪽 위치일 수도 있고, 가장 왼쪽 위치가 mid 보다 작을 수도 있으므로 en을 mid로 변경한다

      ![4](https://user-images.githubusercontent.com/48282185/178326349-9dfd11fd-f773-48d2-83e5-a9ff73f282aa.png)

    - 그리고 다시 mid를 (st + end) / 2로 바꿔주면 st = en = mid가 되고, 이 위치가 10이 들어갈 수 있는 가장 왼쪽 인덱스가 된다, 원소가 중복되지 않더라도 순서를 유지하면서 들어갈 수 있는 위치이다

    ```cpp
    int lower_idx(int target, int len){
     int st = 0;
     int en = len;
     while(st < en){
      int mid = (st + en) / 2;
      if(a[mid] >= target) en = mid;
      else st = mid + 1;
     }
     return st;
    }
    ```

    - 가장 오른쪽 인덱스도 비슷한 논리로 구할 수 있는데, target보다 큰 수가 최초로 등장한 위치를 찾는 것이고, a[mid] > target일 때 en을 mid로 반대일 때는 st를 mid + 1로 변경하여 범위를 좁혀나간다.

    ```cpp
    int upper_idx(int target, int len){
     int st = 0;
     int en = len;
     while(st < en){
      int mid = (st + en) / 2;
      if(a[mid] > target) en = mid;
      else st = mid + 1;
     }
     return st;
    }
    ```

    - 위 사실을 바탕으로 특정 원소가 배열 내에서 몇 개 존재하는지 확인하기 위해서 upper_idx(target, len) - lower_idx(target, len)을 하면 된다
    - 여기서 교훈은 정렬과 이분 탐색을 활용하면 빈도수를 알 수 있다는 것
    - STL
      - 위에서 구현했던 upper_idx와 lower_idx의 역할을 하는 함수가 STL에 내장되어있다. 이름은 각각 upper_bound, lower_bound이고, 범위와 target을 인자로 받고 반환값은 배열을 인자로 넣으면 포인터가 vector를 넣으면 iterator가 된다

## 0x02 연습 문제 1 - 좌표 압축

- 18870 - 좌표 압축 풀이

  - 정렬한다
  - 중복제거한다
  - 이분탐색한다

  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  int binary_search(int target, vector<int>& arr) {
    int st = 0;
    int en = arr.size() - 1;
    while (st <= en) {
      int mid = (st + en) / 2;
      if (arr[mid] > target)
        en = mid - 1;
      else if (arr[mid] < target)
        st = mid + 1;
      else
        return mid;
    }
    return -1;
  }

  int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[n], copied_arr[n];
    vector<int> uniq;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      copied_arr[i] = arr[i];
    }
    sort(copied_arr, copied_arr + n);
    for (int i = 0; i < n; ++i) {
      if (i == 0 or copied_arr[i] != copied_arr[i - 1])
        uniq.push_back(copied_arr[i]);
    }
    for (int i = 0; i < n; ++i) {
      cout << binary_search(arr[i], uniq) << ' ';
    // lower_bound로도 뽑아낼 수 있지만, 연습 차원에서 다시 한 번 구현해봤음
    // cout << lower_bound(uniq.begin(), uniq.end(), arr[i]) - uniq.begin() << ' ';
    }
    return 0;
  }
  ```

- STL을 이용하여 중복제거를 쉽게할 수 있다

  ```cpp
  // 정렬된 상태에서 unique함수를 호출해야한다
  // unique함수는 중복 제거된 원소들을 첫번째 인덱스부터 배치시키고 남은 칸은 쓰레기 값으로 메꿔져서
  // erase를 활용하여 쓰레기 값을 제거함
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  ```

## 0x03 연습 문제 2 - 세 수의 합

- 막막한데 일단 떠올릴 수 있는 간단한 풀이부터 시작해서 점차 범위를 줄여나가보자
- 제일 간단한 해법
  - a[i] + a[j] + a[k] = a[l]을 만족하는 a[l] 중에 최댓값을 찾는 문제이므로 i, j, k, l에 대해 4중 for문 → O($N^4$)
- 여기서 배운 이분탐색으로 최적화
  - i, j, k에 대한 3중 for문 + 합이 집합 내에 있는가 이분 탐색 → O($N^3log{N}$)
  - 입력 크기가 1000이고 시간 제한이 1초라 불가능
  - 최소 $O(N^2)$은 되야 제한 내에 해결할 수 있음
- 그럼 $O(N^2)$으로 만들기 위해 어떤 최적화를 할 수 있을까?
  - 2중 for문 + 이분 탐색으로 해결할 수 있지 않을까?
  - 2중 for문으로 만들기 위해 어떤 아이디어를 생각해볼 수 있을까?
  - 집합 내의 임의의 원소 두 개를 뽑아 그 합을 미리 구해놓고, 2중 for문을 돌면서 a[l] - a[k]가 구해놓은 합 배열 내에 있는지 이분탐색으로 검색
  - 합 배열의 크기는 $N^2$이고 log를 씌우므로 이 방법의 시간복잡도는 $O(N^2logN)$이다
- 이 문제와 같이 세 쌍 이상의 조합을 묶고 어느 한 값을 이분탐색으로 찾아 시간복잡도를 낮추는 아이디어는 이분탐색 유형의 핵심 아이디어로 다양한 문제를 풀어서 익혀보자

## 0x04 Parametric Search

- 문제 유형이 parametric search인 것을 눈치채기 어렵고, dp나 greedy와 짝꿍으로 많이 나오는 편
- 그래서 이게 뭐냐?
  - 조건을 만족하는 최소/최대값을 구하는 문제(최적화 문제)를 결정 문제로 환원해 이분탐색을 수행하는 방법
- 1654 - 랜선 자르기

  - N개를 만들 수 있는 랜선의 `최대` 길이 → 최적화 문제
  - 랜선의 길이가 x일 때 랜선이 N개 `이상인가 아닌가?` → 결정 문제
  - 토막내는 랜선의 길이가 짧을 수록 더 많은 랜선을 만들어 낼 수 있다 즉, 랜선 길이와 N은 반비례 관계이다

    ![6](https://user-images.githubusercontent.com/48282185/178326344-81c79d03-753a-4b84-994d-5b51608e5825.png)

  - 랜선의 길이를 x로 두고 나면 조각의 개수를 구하는 문제는 O(N)이고, 범위는 $2^{31}$이기에 O(31N)에 풀이가 가능하다
  - 주의할 사항은 두 변수를 가지고 결정 문제로 변환했을 때 두 변수의 관계가 비례관계거나 반비례관계여야 이분탐색을 수행할 수 있다, 아래 그림과 같이 뒤죽박죽이면 불가능

    - 범위를 줄여가면서 탐색하는데 아래와 같이 비례 혹은 반비례 관계가 아니면, 어느 구간에 최적의 값이 위치하는지 알 수 없기때문에 이분탐색을 적용할 수 없다

    ![7](https://user-images.githubusercontent.com/48282185/178326331-ea9a76d9-87e0-413b-b392-96cce03f4034.png)

  - 정리하면 parametric search를 할 때는 최적화 문제가 결정 문제로 바뀔 수 있는지를 보고, 결정 문제로 바꿀 수 있다면 변수 관계가 비례 / 반비례 관계인지 봐야한다
  - 문제가 parametric search로 풀릴 수 있는지 유심히 살펴볼 경우들
    - 문제에서 최소값 혹은 최대값을 구하라고 할 때
    - 범위가 엄청 클 때
    - 최적화를 고민해보다가 시간복잡도에서 값 하나를 로그를 적용할 수 있을 것 같을 때
  - 이분 탐색이 무한루프를 돌 때 살펴봐야 하는 것
    - st와 en이 1차이 날 때, st값이 갱신되지 않아서, 무한루프를 도는 경우가 많다
    - 이럴 때는 mid = (st + en + 1) / 2로 변경하자

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
