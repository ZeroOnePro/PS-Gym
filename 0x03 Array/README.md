## 0x00 정의와 성질

1. O(1)의 연산으로 k번째 원소를 확인/수정 가능
2. 추가적으로 소모되는 메모리의 양(overhead)가 거의 없음
3. cache hit rate가 높다.(연속적으로 위치하기 때문)
4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림

## 0x01 기능과 구현

1. 원소를 끝에 추가 - O(1)
2. 마지막 원소 제거 - O(1)
3. 임의의 위치에 원소를 추가(추가된 원소를 기준으로 기존의 원소들을 뒤로 밀어야함) - O(N)
4. 임의의 위치의 원소를 제거 - O(N)

- 임의의 원소 추가 / 삭제 구현해보기

처음에는 copied라는 배열 만들고 배열을 전달받은 배열의 길이 보다 1크게 할당한 다음에 for문으로 하나씩 당겨왔었는데, 아래의 답안은 굳이 새로운 배열을 생성하지 않더라도 가능함을 알려주네... 조금만 더 효율적으로 짤 수 없는지 고민해보자

```cpp
# include<bits/stdsc++.h>

using namespace std;

void insert(int idx, int num, int arr[], int& len){
  // 맨끝에 한 칸을 만들고 오른쪽부터 한 칸씩 땡겨온다.
	for(int i = len; i > idx; i--)
		arr[i] = arr[i-1];
	arr[idx] num;
	len++;
}

void erase(int idx, int arr[], int& len){
	len--;
	// 왼쪽부터 하나씩 당겨오고 맨 끝 원소 삭제
	for(int i = idx; i < len; ++i) 
		arr[i] = arr[i+1];
}

void printArr(int arr[], int& len){
	for(int i=0; i < len; ++i) cout << arr[i] << ' ';
	cout << '\n\n';
}
```

- 특정 값으로 배열을 초기화 하기
    - fill함수 사용

```cpp
fill(a, a+21, 0);
```

## 0x02 STL vector에 관하여

- 배열과 차이점은 크기를 자유자재로 늘이거나 줄일 수 있음
- insert, erase 임의의 위치에 원소 추가 / 삭제 → O(N)
- push_back, pop_back, 제일 끝 위치의 원소 추가 / 삭제 → O(1)
- "="연산자로 백터의 주소 끼리 대입연산을 하면 deep copy가 일어나서 원본에 영향을 끼치지 않는다.

![Untitled](https://user-images.githubusercontent.com/48282185/143925433-e57488de-7497-4096-93d7-f1677612727e.png)

- vector의 size 메서드는 시스템에 따라 unsigned int 혹은 unsigned long long을 반환를 하기에 vector가 비어있을 경우 v.size() - 1이런식으로 사용하게 되면 오버플로우 발생하여 의도대로 수행되지 않을 수 있다.
- range based for loop(≤ c++ 11)

```cpp
// 참조자를 씀으로써 seq vector의 실제 원소들이 2로 수정됨
for(int& elem : seq){
	elem = 2;
}
```

## 0x03 연습문제

- 데이터를 자주 바꾸지 않고 쌓아두고 싶을 때 활용될 수 있음( ex)입력을 담아두는 용도)

- 10808 알파벳 갯수
    - 인덱스에 해당하는 원소를 빠르게 접근하려는 목적으로 배열을 사용하면 효율적으로 풀리는 문제
    - 빈도수 배열

** 본 내용은 바킹독님의 유튜브 실전 코딩테스트 강의의 내용을 기반으로 제작되었습니다 **