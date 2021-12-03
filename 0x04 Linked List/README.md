# 0x04 연결리스트

### 0x00 정의와 성질

- 원소들을 저장할 때 그 다음 원소의 위치를 포함하여 같이 저장하는 자료구조
- 원소가 이곳 저곳에 흩어져있다.
- k번째 원소를 확인/변경하기 위해 O(k)가 필요함
- 임의의 위치에 원소를 추가/임의 위치의 원소 제거는 O(1) ⇒ 배열과 비교 시 가장 큰 장점
- 원소들이 메모리 상에 연속해있지 않아 cache hit rate가 낮지만 할당이 다소 쉬움
- 종류
    - 단일 연결 리스트 - 각 원소가 자신의 다음원소의 위치를 저장
    - 이중 연결 리스트 - 각 원소가 자신의 이전와 다음원소의 주소를 둘 다 가지고 있다.
    - 원형 연결 리스트 - 처음과 끝이 이어져있음
- 배열 vs 연결 리스트
    
    ![Untitled](https://user-images.githubusercontent.com/48282185/144294653-fb8f88f9-d2fb-4aea-8426-6b0f59410908.png)
    

### 0x01 기능과 구현

- 연결리스트의 사용을 고려해볼 경우는 임의의 위치에 원소를 추가하거나 임의 위치의 원소를 제거하는 연산이 많이 사용되는 경우
    - 텍스트 에디터 - 임의의 위치에 커서가 놓이고 거기서 텍스트를 입력하거나 제거할 수 있다.
    - 운영체제 스케쥴러 - linux_list를 이용하여 구현했었다. 프로세스 실행 순서가 임의의 위치에 웨이트 큐에 삽입 되거나 삭제될 수 있기 때문

```cpp
struct Node {
	struct Node *prev, *next;
	int data;
}
```

- 연결 리스트의 다른 구현 방식

![Untitled](https://user-images.githubusercontent.com/48282185/144294751-c7e74e91-2fa2-4602-ad38-e61316ccc7ac.png)

- data
    - 0번째는 실제로는 쓰이지 않지만 관념적 시작 위치(예외처리 시 용이)
    - data가 -1이면 앞에 원소가 없거나 뒤에 원소가 없음(시작과 끝)을 의미
- prev - 이전 원소의 인덱스(주소 대용)
- next - 다음 원소의 인덱스(주소 대용)
- unused - 현재 사용되지 않는 인덱스 즉 새로운 원소가 들어갈 수 있는 인덱스 이고, 원소 추가 이후에는 1씩 증가됨
- 메모리 누수 때문에 실무에서는 절대 쓸 수 없는 방식

- 삽입 구현

```cpp
const int MX = 1000005;

int unused = 0;
int data[MX], prev[MX], next[MX];

void insert(int addr, int num){
	data[unused] = num;
	prev[unused] = prev[addr];
	next[unused] = next[addr];
	if(next[addr] != -1) prev[next[addr]] = unused;
	next[addr] = unused;
	unused += 1;
}
```

주의할 점은 맨 마지막 원소 뒤에 새 원소를 추가하는 상황이라면 "삽입할 위치의 다음 원소가 존재하지 않는다" 이것을 고려하지 않고 `prev[next[addr]] = unused;` 한다면 `prev[-1]` 에 접근하게 될 수도 있다. 

- 삭제 구현

```cpp
const int MX = 1000005;

int unused = 0;
int data[MX], prev[MX], next[MX];

void erase(int addr){
	next[prev[addr]] = next[addr];
	if(next[addr] != -1) prev[next[addr]] = prev[addr];
}
```

- `prev[addr]`이 -1인 경우는 고려할 필요가 없다? ⇒ 시작 더미 노드의 존재로 인해 prev[addr] = -1이 아님이 보장 되기 때문 더미노드는 관념적 시작점이지 실제 리스트에 포함되는게 아님을 명심하자!

### 0x02 STL list

```cpp
int main(void){
	list<int> L = {1,2};
	list<int>::iterator start = L.begin(); // 시작 원소인 1을 가리킨
	L.push_front(10); // 10 1 2
	cout << *t << '\n'; // t가 가리키는 값 1 출력
	L.push_back(5); // 10 1 2 5
	L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입 10 6 1 2 5
	t++; // t를 1칸 next, t는 2를 가리킴
	t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
	
	cout << *t << '\n';
	for(auto i : L) cout << i << ' ';
	for(List<int>::iterator it - L.begin(); it != L.end(); ++it){
		cout << *it << ' ';
	}
}
```

- push_back, pop_back, push_front, pop_front의 시간복잡도는 O(1)이다.
- iterator가 주소 역할
- push_back을 하면 끝 원소(list.end())가 가리키는 게 리스트의 끝 원소가 아닐 수 있음에 주의

- circular linked list구현 시 iterator를 아래와 같이 짜봤는데 정상적으로 동작했다.

```cpp
list<int>::iterator ForCircularIterator(list<int> &l, list<int>::iterator &iter)
{
  return std::next(iter) == l.end() ? l.begin() : std::next(iter);
}
```


### 0x03 연습 문제

- 1406 에디터
- 원형 연결 리스트 내의 임의의 노드 하나가 주어졌을 때 해당 List의 길이를 효율적으로 구하는 방법?
    - 자기 자신이 나오기 전까지 돌아보면 되지않나? o(n) ⇒ 정답

- 중간에 만나는 두 연결 리스트의 시작점들이 주어졌을 때 만나는 지점을 구하는 방법?
    - 일단 두 시작점 각각에 대해 끝까지 진행시켜서 각각의 길이를 구함
    - 그 후 다시 두 시작점으로 돌아와서 더 긴 쪽을 둘의 차이만큼 앞으로 먼저 이동 시킴
    - 두 시작점이 만날 때 까지 두 시작점을 동시에 한 칸씩 전진시키면 됨.
    - 공간복잡도 O(1), 시간 복잡도 O(a+b)
    - 나는 둘 다 동시에 출발시켜서 어긋나는 지점 찾으려고 했다
    - 애시당초에 문제를 잘못이해한 것 같다. 문제를 잘 읽자!
    
    ![Untitled](https://user-images.githubusercontent.com/48282185/144294838-081db8ef-f22a-478c-b427-48617ed1b83c.png)

    

- 주어진 연결 리스트 안에 사이클이 있는지 판단하라

![Untitled](https://user-images.githubusercontent.com/48282185/144294908-acd63854-ba6a-4eeb-a926-1d4a4acd8d78.png)


- 한 칸씩 이동하는 커서와 두 칸씩 이동하는 커서를 동시에 출발시킨다.
- 사이클이 존재하면 두 커서는 반드시 만난다.
- 하지만 사이클이 없을 경우 두 커서는 만날 수 없다.


** 본 자료는 바킹독님의 실전 알고리즘 강의를 바탕으로 제작되었습니다 **