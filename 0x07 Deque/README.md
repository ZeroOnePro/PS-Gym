## 0x00 정의와 성질

- double ended queue
- restricted structure의 끝판왕 느낌의 자료구조
- 양쪽 끝에서 삽입과 삭제가 전부 가능
- 스택과 큐는 덱의 특수 예시
- 원소의 추가 O(1)
- 원소의 제거 O(1)
- 제일 앞/뒤의 원소 확인 O(1)
- 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능
- STL 덱에서는 인덱스 접근이 가능하다!!

## 0x01 기능과 구현

### 1. 배열로 구현(연결리스트로도 가능)

```cpp
const int MX = 1e6;
int deque[2*MX]; // 양쪽에서 삭제가능
int head = MX, tail = MX; // 삽입이 양쪽에서 가능하기에 중간에서부터 채워나가는 것이 전략적이다.
// 추가를 하려고하는데 0이나 배열의 마지막 인덱스면 안돼잖아

// tail은 마지막 원소를 가리키는 게 아니라 마지막 원소 + 1이라고 생각
void push_front(int x){
		deque[--head] = x;
}

void push_back(int x){
		deque[tail++] = x; 
}

void pop_front(){
	head++;
}

void pop_back(){
	tail--;
}

int front(){
	return deque[head];
}

int back(){
	return deque[tail-1];
}
```

### 2. STL deque

```cpp
int main(){
	deque<int> dq;

	dq.push_front(10); // void
	dq.push_front(50); 
	dq.push_front(24);
	
	dq.size(); // size_t

	dq.empty(); // bool

	dq.pop_front(); // void
	dq.pop_back(); // void

	dq.back() // int
  dq.front() // int

	dq.push_back(72); // void
	dq.insert(dq.begin()+1, 33) // 인덱스로 접근 가능
	dq.erase(dq.begin()+1)
	dq.clear() // 모든 원소 제거 
}
```

- 공식문서에도 나와있듯 vector와 deque은 비슷하다
- vector와의 차이는 deque은 메모리 상에 연속적으로 위치하지 않는다!

** 본 자료는 바킹독님의 실전 알고리즘 강의를 바탕으로 제작되었습니다 **