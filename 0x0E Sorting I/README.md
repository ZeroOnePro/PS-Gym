# 0x0E 정렬 I

오름차순을 기준으로 정리했음

## 0x00 기초 정렬

- 선택정렬

  - 제일 큰 것을 골라 제일 뒤쪽에 배치하는 정렬방법

  ```cpp
  void selection_sort(int n){
   for(int i = n-1; i > 0; --i){
    swap(*max_element(arr, arr+i+1), arr[i]);
   }
  }
  ```

  - 시간복잡도
    - 제일 큰 원소를 검색하는 시간 O(N)
    - 모든 원소를 하나하나 살펴보는 시간 O(N)
    - 곱사건이므로 O($N^2$)

- 버블정렬

  - 인접한 두 원소를 비교해가면서 제일 끝자리에 제일 큰 원소가 배치되게 하는 정렬방법

  ```cpp
  void bubble_sort(int n){
   for(int i=0; i<=n-1; ++i)
    for(int j=0; j < n-1-i; ++j)
     if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
  }
  ```

  - 시간복잡도
    - 제일 큰 원소가 제일 뒤로 배치되는 시간 O(N)
    - 모든 원소를 인접 원소와 쌍을 이뤄 살펴보는 시간 O(N)
    - 곱사건이므로 O($N^2$)

- 삽입정렬

  - 두 번째 원소부터 시작하여 그 앞(왼쪽)의 원소들과 비교하여 삽입할 위치를 지정한 후 비교 되는 위치의 원소가 삽입할 원소보다 크면 비교되는 위치의 원소를 뒤로 옮기고 지정한 자리에 원소를 삽입하는 정렬방법

  ```cpp
  void insertion_sort(int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (arr[j] > arr[j + 1])
          swap(arr[j], arr[j + 1]);
        else
          break;
      }
    }
  }
  ```

  - 시간복잡도
    - 모든 원소를 하나하나 살펴보는 시간 O(N)
    - 삽입될 원소의 앞 부분 배열에서 삽입 위치를 탐색하는 시간 O(N)
    - 곱사건이므로 O($N^2$)

## 0x01 Merge Sort

- 재귀적으로 수열을 나눠 정렬한 후 합치는 정렬법
- 머지소트를 이해하기 위해서는 길이가 각각 N, M인 두 수열을 합쳐서 길이가 N+M인 정렬된 수열을 만드는 방법부터 알아야한다

  ![1](https://user-images.githubusercontent.com/48282185/176086574-03c154ee-45de-4edd-becc-ea570e6e61f6.png)

  - 제일 앞에 올 원소는 두 수열의 가장 첫번째 원소끼리 비교하는 것이다
  - -9와 -7을 비교 -9 제일 앞, 1과 -7을 비교 -7이 두 번째…
  - 비교 한 번당 제자리 보낼 수 있으니 O(N+M)

  ```cpp
  #include <bits/stdc++.h>

  using namespace std;

  int n, m;
  int a[1000002];
  int b[1000002];
  int merged[2000004];

  void merge_sort() {
    int a_cur = 0, b_cur = 0, index = 0;
    while (index < n + m) {
      if (a_cur == n)
        merged[index++] = b[b_cur++];
      else if (b_cur == m)
        merged[index++] = a[a_cur++];
      else if (a[a_cur] <= b[b_cur])
        merged[index++] = a[a_cur++];
      else if (a[a_cur] >= b[b_cur])
        merged[index++] = b[b_cur++];
      else
        continue;
    }
  }

  void print_result(int n, int *list) {
    for (int i = 0; i < n; ++i) {
      cout << list[i] << ' ';
    }
    cout << '\n';
  }

  int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    merge_sort();
    print_result(n + m, merged);
    return 0;
  }
  ```

  - merge sort는 각 단계에서 크게 두 가지 연산이 수행됨
    - 주어진 리스트를 이등분한다
    - 나눈 리스트 2개를 정렬한다
  - 여기서도 귀납적인 관점에서 정렬이 됨을 증명해볼 수 있다.
    - 길이가 1인 리스트를 정렬할 수 있다
    - 길이가 N인 두 정렬된 리스트를 합칠 수 있다
    - 길이가 N인 리스트를 정렬할 수 있으면 길이가 2N인 리스트를 정렬할 수 있다
  - 시간복잡도

    ![2](https://user-images.githubusercontent.com/48282185/176086572-fb7c92a6-a359-4055-a138-14a71569fa8a.png)

    - 길이 $2^k$ = N인 리스트의 분할 횟수는 1 + 2 + 4 + … + $2^k$ = 2N - 1 → O(N)
    - 길이 $2^k$ = N인 리스트의 병합 횟수는 길이 N, M인 두 배열을 정렬된 상태로 합치는 것은 앞서봤듯 O(N + M)이고, 이 경우 같은 분할 크기(N)을 합치는 것이므로 각 깊이에서 2N이 수행됨, 깊이는 k이므로 둘을 곱하면 k \* N = NlogN → O(NlogN)

  - stable sort

    ![3](https://user-images.githubusercontent.com/48282185/176086568-51843c2d-62b9-4b99-ad2e-e772dc411178.png)

    - 우선순위가 같은 원소들끼리 원래의 순서를 따라가도록 하는 정렬
    - 21세 사람 세 명이 있고, 이들은 우선순위가 같으므로 21세끼리는 어떻게 정렬되던 정답인데, stable sort는 정렬 전 순서를 그대로 보존하여 위의 예시에서 파랑, 빨강, 초록이 유지됨이 보장된 상태로 정렬되는 것을 의미
    - 앞 리스트의 원소와 뒤 리스트의 원소의 우선순위가 같을 때 앞 리스트의 원소를 먼저 보내 줌으로서 merge sort에서 stable sort를 구현할 수 있다
    - 응용 예시(정렬 기준이 두 개 이상일 때 활용될 수 있음)
      - 파일들을 정렬할 때 생성 시간을 기준으로 오름차순으로 정렬 되있다고 하자 . 이 때 파일을 크기 순으로, 크기가 동일하다면 빨리 생성된 순으로 정렬하고 싶다. 이 때는 시간과 무관하게 파일 크기를 기준으로 stable sort를 사용하면 기존 순서가 유지되므로 원하는 결과를 얻을 수 있다
      - 2차원 좌표들을 x가 작은 순으로, x가 동일하다면 y가 작은 순으로 정렬하고 싶다. 먼저 y의 크기를 기준삼어서 stable sort를 수행하고, x의 크기를 기준으로 stable sort를 수행한다

## 0x02 Quick Sort

- 대부분 언어의 정렬함수는 퀵소트 기반으로 구현되어있음
- 재귀적으로 구현됨
- 매 단계마다 pivot이라고 이름 붙은 원소 하나를 제자리로 보내는 작업을 반복한다

  - 제자리로 보낸다는 것은 pivot을 어떤 위치에 놓았을 때, 왼쪽은 pivot보다 작은 원소들이 오른쪽은 큰 원소들이 위치한다는 것을 의미한다
  - pivot을 제자리로 보내고나면 왼쪽 구간과 오른쪽 구간을 각각 정렬한다
  - 왼쪽 구간과 오른쪽 구간에서 각각 pivot을 선정한 뒤 같은 작업이 재귀적으로 반복된다

  ```cpp
  void quick_sort() {
    int tmp[8] = {};
    int pivot = arr[0];
    int index = 0;
    for (int i = 1; i < 8; ++i) {
      if (arr[i] <= pivot) tmp[index++] = arr[i];
    }
    tmp[index++] = pivot;
    for (int i = 1; i < 8; ++i) {
      if (arr[i] > pivot) tmp[index++] = arr[i];
    }
    copy(tmp, tmp + 8, arr);
  }
  ```

  - 잘 동작하지만 퀵소트의 장점을 상쇄시키는 코드이다. 퀵소트의 장점은 추가적인 공간이(tmp) 필요하지 않다는 점이다
  - 추가적인 공간을 필요로 하지 않는 정렬은 In-Place Sort라고 한다
  - 원본 배열내에서 자리 바꿈만으로 처리가 되기 때문에 cache hit rate가 높아서 속도가 빠르다는 장점도 따라온다
  - 그래서 다른 방법을 필요로 하는데 두 개의 포인터를 이용하면서 적절하게 swap시키는 방법이다.
  - 왼쪽 포인터는 오른쪽으로 이동하면서 pivot보다 큰 값이 나오면 멈추고, 오른쪽 포인터는 왼쪽으로 이동하면서 pivot보다 작은 값이 나오면 멈춰서 두 원소를 swap하고 두 포인터가 엇갈릴 때까지 이 작업을 반복한다 엇갈리고 오른쪽 포인터가 멈춘 이후 pivot과 오른쪽 포인터가 가리키는 원소를 swap하면 한 단계가 끝남
  - 이 방법이 어떻게 pivot을 제자리로 보내는지에 대한 정당성은 모든 순간에서 왼쪽 포인터 왼쪽에는 pivot보다 작은 값이 위치하고 오른쪽 포인터 오른쪽에는 pivot보다 큰 값이 위치하기 때문에 왼쪽 포인터와 오른쪽 포인터가 엇갈렸다는 것은 과정이 끝났음을 의미, 각 포인터가 구간을 훑고 지나가면서 왼쪽포인터는 pivot보다 작은 값임을 오른쪽 포인터는 pivot보다 큰 값임을 이미 보였기 때문에 그렇다

  ```cpp
  void quick_sort() {
    int pivot = arr[0];
    int l_cur = 1, r_cur = 7;
    while (true) {
     while(l_cur <= r_cur && arr[l_cur] <= pivot) l_cur++;
    while(l_cur <= r_cur && arr[r_cur] > pivot) r_cur--;
    if(l_cur > r_cur) break;
    swap(arr[l_cur], arr[r_cur]);
    }
    swap(arr[r_cur], arr[0]);
  }
  ```

- 구현

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;

  int n = 10;
  int arr[1000001] = {15, 25, 22, 357, 16, 23, -53, 12, 46, 3};

  void quick_sort(int st, int en) { // arr[st to en-1]을 정렬할 예정
    if(en <= st+1) return; // 수열의 길이가 1 이하이면 함수 종료.(base condition)
    int pivot = arr[st]; // 제일 앞의 것을 pivot으로 잡는다. 임의의 값을 잡고 arr[st]와 swap해도 상관없음.
    int l = st+1; // 포인터 l
    int r = en-1; // 포인터 r
    while(1){
      while(l <= r && arr[l] <= pivot) l++;
      while(l <= r && arr[r] >= pivot) r--;
      if(l > r) break; // l과 r이 역전되는 그 즉시 탈출
      swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r+1, en);
  }

  int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    quick_sort(0, n);
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
  }
  ```

- 시간복잡도

  ![4](https://user-images.githubusercontent.com/48282185/176086565-4046b722-302d-4e9a-8b7b-c4cda1d52061.png)

  - 평균 시간복잡도는 pivot이 중앙에 위치할 경우 → O(NlogN)
  - 이미 정렬된 리스트를 다시 정렬하면 pivot이 매번 제일 왼쪽에 위치하게 되므로 단계의 수가 logN이 아니라 N개가 된다.(크기 1인 배열들로 완전 분할까지 걸리는 단계의 수) → O($N^2$)이 된다

    ![5](https://user-images.githubusercontent.com/48282185/176086560-dbb62f3b-e9e4-45f8-b737-164d997026d9.png)

  - 그럼 최악의 경우 시간복잡도가 O($N^2$)인데 대부분의 언어에서 지원하는 정렬은 왜 퀵소트를 기반으로 할까?
    - pivot을 랜덤으로 선택
    - pivot후보를 3개 정해서 그 3개 중에서 중앙값을 피벗으로 둔다
    - O(NlogN)을 보장하기위해 일정 깊이 이상 깊어지면 힙소트(Heap Sort)로 대체된다 이러한 방식을 introspective sort라고 한다

## 0x03 Merge Sort vs Quick Sort

![6](https://user-images.githubusercontent.com/48282185/176086548-e4816491-180b-4399-8b31-a431f80fc45d.png)

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
