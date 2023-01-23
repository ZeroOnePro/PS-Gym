# 0x15 해시

<!--ts-->

- [0x15 해시](#0x15-해시)
  - [0x00 정의와 성질](#0x00-정의와-성질)
  - [0x01 충돌 회피 1 - Chaining](#0x01-충돌-회피-1---chaining)
  - [0x02 충돌 회피 2 - Open addressing](#0x02-충돌-회피-2---open-addressing)
  - [0x03 STL](#0x03-stl)
  - [0x04 연습 문제](#0x04-연습-문제)
  - [0x05 구현](#0x05-구현)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 7월 15일 금요일 01시 02분 53초 KST -->

<!--te-->

## 0x00 정의와 성질

- 키에 대응되는 값을 저장하는 자료구조
- insert, erase, find, update 연산이 모두 O(1)에 가능하다
- 해시 함수는 임의 길이의 데이터를 고정된 길이의 데이터로 대응시키는 함수
- 해시 함수의 목적은 매우 큰 경우의 수를 가진 정의역을 작은 경우의 수를 가진 치역에 대응시키는 데 있다
- 해시 자료구조에서는 서로 다른 키가 같은 해시 값을 가리키는 충돌이 가장 큰 문제이고, 이것을 어떻게 해결하느냐에 따라 성능 차이가 난다
- 본래의 목적에 따라 충돌을 막을 방법은 없지만, 회피할 수 있는 방안들이 있는데 크게 chaining과 open addressing이다
- key - value쌍의 데이터들이 삽입, 검색, 갱신, 삭제가 자주 일어나는 문제들에 적용해볼 수 있겠네

## 0x01 충돌 회피 1 - Chaining

- 각 인덱스마다 연결 리스트를 둬서 충돌 회피하는 방법
- 서로 다른 키에 대응하는 값이 같아서 문제였는데 서로다른 키가 같은 값을 가리키더라도 값 자체를 연결 리스트로 둬서 여러 경우의 수에 대응할 수 있게 만들어준다, 즉 삽입할 때 연결 리스트에 추가되는 방식

  ![1](https://user-images.githubusercontent.com/48282185/179026019-21c3fbeb-4d5e-4feb-91f4-c5cb7f9ee590.png)

  - 서로 다른 키 0000 0000 0000 5135와 9999 9999 9999 5135는 끝 네자리만 리턴하는 해시 함수에 따라 같은 공간을 가리키게 되는데, 이 공간이 연결리스트라 이미 값이 있어도 연결리스트에 값이 추가되는 것이기 때문에 문제가 없어지게 된다

- STL에 정의된 해시에서 사용하는 방법이기도 하다
- 최악의 경우 모든 키가 같은 값을 가리킬 수도 있다 이 때는 하나의 연결리스트에서 insert, update, find, erase가 수행되고, insert의 경우는 O(1)에 해결가능하지만, 나머지는 O(N)이기에 충돌이 나면 날수록 해시의 시간복잡도는 O(N)으로 수렴하게되어 성능이 안 좋아 지는 것이다

## 0x02 충돌 회피 2 - Open addressing

- chaining과 다르게 그냥 각 인덱스에 바로 (키, 값) 쌍을 저장

  - 3333 충돌돼서 3334에 저장했다고하자 이후 3334가 들어왔을 때 이게 3333이 충돌나서 3334에 저장된 것인지 3334의 데이터로 저장된 것인지 구분할 방법이 필요한데, index를 두고, 이 index가 충돌나면 키의 충돌이라고 판단하고 뒤로 밀어주는 방식으로 구성되있다, 저장할 때 <인덱스, 오리지날 키, 값>으로 저장하게 됨

    [참고한 블로그](https://bcho.tistory.com/1072)

- 해당 키에 값을 삽입하려고 보니 이미 값이 있을 경우 다음 키에 값을 써준다, 그리고 그 다음 키에도 있을 경우 다다음 키에 써주고, … 이런 방식으로 이어 나가는 방식

  ![2](https://user-images.githubusercontent.com/48282185/179026014-f6c0566b-e759-488d-8513-45b2cfd1fb18.png)

  - insert의 예시 3333이 충돌나서 3334, 3335, 3336에 저장되는 상황
  - find는 3333부터 시작해서 빈 공간을 만날 때(만약 밀려서 저장됬다면 있었을 건데 없으니)까지 계속 탐색
  - erase는 해당 키 값에 저장된 자료를 지우면 되는데 그러면 find에서 문제가 생긴다 만약 위의 예시에서 3334에 저장된 6278 5651 9104 3333을 지우고 그 이후 3492 0658 8348 3333을 find하는 상황을 가정해보자, 3334가 지워졌기 때문에 연속적으로 저장되지 않아 3334를 지울 때 빈공간으로 놔두게 되면 3492 0658 8348 3333는 찾을 수 없게 된다 그래서 단순히 지우는게 아니라 지울 때 dummy나 쓰레기값을 둬서 ‘값을 가지고 있었지만 erase때문에 삭제됬다’를 표현해줄 필요가 있고, find해줄 때도 dummy나 쓰레기값을 만나도 계속 다음 키로 탐색을 이어가게 해야한다

    ![3](https://user-images.githubusercontent.com/48282185/179026011-46fa1532-ec9c-4113-8856-6ca855c5026f.png)

- Linear Probing

  ![4](https://user-images.githubusercontent.com/48282185/179026004-e71e2b53-a459-4a7a-9078-713e817ee210.png)

  - 충돌 발생 시 오른쪽으로 한 칸씩 이동하는 방식
  - 장점
    - 구현이 간단
    - cache hit rate가 높음
  - 단점

    - clustering(데이터의 군집, 위의 예시에서는 노란색 칸들을 의미)이 생겨 성능에 영향을 줄 수 있다

      ![5](https://user-images.githubusercontent.com/48282185/179026002-ba0c0dcd-2d09-4b52-818b-beae90f22bf0.png)

      - 만약 cluster에 포함된 키에 대응되는 값을 삽입해야할 때는 cluster가 끝날 때까지(빈 공간을 찾을 때까지)이동해서 그 부분에 삽입해야하는데, 삽입이 일어날 때마다 빈 공간을 찾는 연산이 수행돼서 성능이 저하된다

- Quadratic Probing

  ![6](https://user-images.githubusercontent.com/48282185/179025997-e02fd10e-a169-40a0-b734-5c7b38dcaed7.png)

  - 충돌 발생 시 오른쪽으로 1, 3, 5, … 칸 씩 이동하는 방식
  - 위치 + $2^N$(N은 양수) + 1로 칸이 이동됨
  - 장점
    - cache hit rate가 나쁘지 않다
    - clustering을 어느정도 회피할 수 있다
  - 단점

    - 해시 값이 같을 경우 여전히 clustering이 발생한다

      ![7](https://user-images.githubusercontent.com/48282185/179025991-3e2cb4e8-05ff-4b26-ae04-ab34f6426fdc.png)

    - linear probing에 비해서는 개선 되기는 했지만 충돌날 수록 여전히 clustering이 발생한다
    - 무슨 말인고 하니 왼쪽에서 세 번째로 나온 노란 칸에 데이터가 들어오면 충돌이 났으므로 quadratic probing 전략에 따라 오른쪽 옆에 저장한다(왼쪽에서 첫번째 노란칸과는 다른 충돌임) 또 왼쪽에서 두 번째 칸에 데이터 들어오면 또 오른쪽 옆에 저장한다 이런식으로 근처에 데이터들이 반복되게되면 결국에는 클러스터링이 발생한다는 것

- Double Hashing

  ![8](https://user-images.githubusercontent.com/48282185/179025974-d807edc2-1dba-4548-b6ea-1d6b69f673b1.png)

  - 충돌 발생 시 이동할 칸의 수를 새로운 해시 함수로 계산하는 방식
  - 말 그대로 두 번 해시함수 쓰겠다
  - 장점
    - clustering을 효과적으로 회피할 수 있다
  - 단점
    - cache hit rate가 극악으로 안 좋아진다

## 0x03 STL

- 앞으로 cpp에서 STL을 참고할 때 이 사이트를 이용하도록 하자

  [unordered_map - C++ Reference](https://cplusplus.com/reference/unordered_map/unordered_map/)

- set은 값이 들어있는지 확인할 때 map은 key에 대응되는 값을 찾아야할 때 이용함

- unordered_set

  ```cpp
  void unordered_set_example(){
    unordered_set<int> s;
    s.insert(-10); s.insert(100); s.insert(15); // {-10, 100, 15}
    s.insert(-10); // {-10, 100, 15}
    cout << s.erase(100) << '\n'; // {-10, 15}, 값이 있었으므로 true 반환
    cout << s.erase(20) << '\n'; // {-10, 15}, 값이 없었으므로 false 반환
    if(s.find(15) != s.end()) cout << "15 in s\n";
    else cout << "15 not in s\n";
    cout << s.size() << '\n'; // 2
    cout << s.count(50) << '\n'; // 몇 개 있는지 확인, 중복 허용안되니 0아님 1이다
    for(auto e : s) cout << e << ' ';
    cout << '\n';
  }
  ```

  - insert(삽입), erase(삭제), find(검색), size(컨테이너 크기), count(특정 원소의 개수)
  - 중복 허용하지 않음
  - 삽입 순서로 저장되지 않음

- unordered_multiset

  ```cpp
  void unordered_multiset_example(){
    unordered_multiset<int> ms;
    ms.insert(-10); ms.insert(100); ms.insert(15); // {-10, 100, 15}
    ms.insert(-10); ms.insert(15);// {-10, -10, 100, 15, 15}
    cout << ms.size() << '\n'; // 5
    for(auto e : ms) cout << e << ' ';
    cout << '\n';
    cout << ms.erase(15) << '\n'; // {-10, -10, 100}, 15가 2개 있었으므로 2를 반환
    ms.erase(ms.find(-10)); // {-10, 100} // 하나만 지우고 싶을 때
    ms.insert(100); // {-10, 100, 100}
    cout << ms.count(100) << '\n'; // 2
  }
  ```

  - insert(삽입), erase(중복원소 전부 삭제), find(검색), size(컨테이너 크기), count(특정 원소의 개수)
  - 중복이 허용된다
  - erase할 때 키에 대응되는 모든 값이 지워지기때문에 주의

- unordered_map

  ```cpp
  void unordered_map_example(){
    unordered_map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; // ("hi", 123), ("bkd", 1000), ("gogo", 165)
    cout << m.size() << '\n'; // 3
    m["hi"] = -7;  // ("hi", -7), ("bkd", 1000), ("gogo", 165)
    if(m.find("hi") != m.end()) cout << "hi in m\n";
    else cout << "hi not in m\n";
    m.erase("bkd"); // ("hi", 123), ("gogo", 165)
    for(auto e : m)
      cout << e.first << ' ' << e.second << '\n';
  }
  ```

  - size(컨테이너 크기), find(검색), erase(삭제)
  - 값이 여러번 들어오면 덮어씌워진다

## 0x04 연습 문제

- 7785 - 회사에 있는 사람

  - 원소의 존재여부를 확인하는 문제 ⇒ 검색이 필요
  - 이분 탐색 풀이법
    - 생각치도 못했는데 이런 방법도 있을 수 있겠구나
    - enter와 leave리스트 각각을 이분 탐색하여 enter와 leave횟수를 센 뒤, enter > leave이면 남아있는 것, 아니면 퇴근한 것으로 판단할 수 있다
      - upper_bound, lower_bound의 차로 몇 개있는지 확인하는 방법
    - enter와 leave를 하나의 리스트에 두고 enter은 +1, leave는 -1 이렇게 정의해서 양수면 남아있는 것, 아니면 퇴근한 것으로 판단할 수도 있겠다
      - pair<name, 1 or -1>이렇게 저장해서 이분탐색하는 방법
  - 투 포인터 풀이법
    - 이분탐색이랑 비슷하게 각 사람마다 enter와 leave에 대한 포인터를 따로둬서 몇 번 전진했는지에 따라 양수이면 남아있는 것 아니면 퇴근 이런 식으로 접근할 수도 있겠다
  - 해시 풀이법
    - unordered_set을 정의한다
    - enter일 때 insert, leave일 때 erase하면 끝
    - 다만 사전순의 역순으로 이름을 출력해줘야하기에 정렬이 필요한데, unordered_set은 정렬이 기본적으로 안되는 자료 구조이기 때문에 벡터로 옮겨서 정렬해줘야한다

- 1620 - 나는야 포켓몬 마스터 이다솜
  - 번호가 주어졌을 때 이름을 답하는 문제는 배열을 써서 해결 가능
  - 이름이 주어졌을 때 번호를 답하는 문제는 이름을 key로 번호를 value로하는 unordered_map을 만들어두면 해결 가능, 이분 탐색으로도 해결 가능
  - 배열에서 값 가져오는 것보다 unordered_map에서 값 가져오는 것이 더 느리다, 배열을 쓸 수 있는 상황이라면 배열을 쓰자
- 뭔가 집합과 같은 식으로 원소를 추가하고 빼는 일이 빈번하거나, 문자열을 수에 대응시키는 것처럼 키를 가지고 값을 알아내야하는 일이 빈번하다면 unordered_set, unordered_map을 활용할 수 있다

## 0x05 구현

- 해시를 구현할 때 고려할 사항은 크게 두 가지로 나뉜다
  - 해시 테이블 크기
  - 해시 함수
- 알고리즘에서는 입력의 크기가 정해져있으므로 최대 삽입횟수도 유추할 수 있다
- Load factor = 원소의 개수 / 테이블의 크기
  - 작을 수록(테이블을 크게 잡으면) 충돌이 덜 생기지만 cache hit rate가 낮아진다
  - 클 수록(테이블을 작게 잡으면) 메모리는 적게차지하지만 충돌이 많이 생긴다
- chaining
  - 충돌이 어느 정도 발생해도 공간의 효율성을 고려해서 Load factor가 1이하가 되게 만든다
- open addressing
  - 거의 다 채워지는 시점에서는 삽입할 공간을 찾느라 아주 느리게 이뤄진다 그렇기 때문에 load factor를 0.75이하 정도로 둔다
- 해시 테이블의 크기는 소수면 좋다고 알려져있다
- 정수에 대한 해시함수는 테이블 크기를 M이라 할 때 M으로 나눈 나머지로 간단하게 정할 수 있다

  ```cpp
  const int M = 1000003;

  // x가 음수인 경우도 고려
  int hash(int x){
   return (M + x % M) % M;
  }
  ```

- 문자열에 대한 해시함수는 테이블의 크기를 M이라 할 때 롤링해시를 써볼 수 있다

  - 롤링해시는 문자열을 진법처럼 취급하는 방법으로 예를 들면 hash(“abc”) = (‘a’ x $1000^2$ + ‘b’ x $1000^1$ + ‘c’ x $1000^0$) % M

  ```cpp
  const int M = 1000003;
  const int base = 1000;

  int hash(string s){
   int h = 0;
   for(char ch : s){
    h = (h * base + ch) % M;
   }
   return h;
  }
  ```

> 바킹독님 유튜브 강의를 참고하여 제작하였습니다.
