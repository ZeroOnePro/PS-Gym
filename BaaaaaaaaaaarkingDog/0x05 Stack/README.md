# 0x05 스택

<!--ts-->

- [0x05 스택](#0x05-스택)
  - [0x00 정의와 성질](#0x00-정의와-성질)
  - [0x01 기능과 구현](#0x01-기능과-구현)
  - [0x02 STL Stack](#0x02-stl-stack)
  - [0x03 연습 문제](#0x03-연습-문제)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 6월 28일 화요일 12시 51분 40초 KST -->

<!--te-->

## 0x00 정의와 성질

- 한 쪽 끝에서만 자료를 빼거나 넣을 수 있는 자료 구조
- FILO(First In Last Out) 자료구조
- 원소의 추가 O(1)
- 원소의 제거 O(1)
- 최상단 원소 확인 O(1)
- 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능
  - 이 말은 스택으로 문제를 풀다가 최상단 원소가 아닌 다른 원소들을 확인하거나 변경해야하는 작업이 생긴다면 문제를 잘못 풀고 있거나, 풀고있는 문제가 스택으로 푸는 문제가 아님을 의심해보자

## 0x01 기능과 구현

- 배열 / 연결리스트로 구현 가능

![image](https://user-images.githubusercontent.com/48282185/144633819-c3661c83-10c9-470f-a591-be1729b41dbc.png)

- 추가, 삭제, 조회 구현

```cpp

const int MX = 1e6 + 5;
int dat[MX];
int pos = 0;

void push(int x){
  dat[pos++] = x;
}

void pop(){
  pos -= 1;
}

int top(){
  return dat[pos-1];
}

```

## 0x02 STL Stack

```cpp

int main(){
  stack<int> s;
  s.push(10); // 10
  s.push(20); // 10 20
  s.push(30); // 10 20 30
  cout << s.size() << '\n'; // 3
  cout << s.empty() << '\n' // false
  s.pop(); // 10 20
  cout << s.top(); // 20
}

```

- push
- pop
- top
- size
- empty

주의할 점은 스택이 비어있을 때 pop이나 top을 하면 런타임에러가 발생할 수 있다!

## 0x03 연습 문제

- stack은 괄호쌍, 전/중/후위표기법, dfs, flood fill 등에서 활용된다.
- 전/중/후위표기법은 코딩테스트에 나올 확률이 거의 0

**본 자료는 바킹독님의 실전 알고리즘 강의를 바탕으로 제작되었습니다**
