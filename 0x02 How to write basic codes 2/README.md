# 0x01 기초 코드 작성 요령 II

<!--ts-->

- [0x01 기초 코드 작성 요령 II](#0x01-기초-코드-작성-요령-ii)
  - [0x01 STL과 함수 인자](#0x01-stl과-함수-인자)
  - [0x02 표준 입출력](#0x02-표준-입출력)
  - [0x03 코드 작성 팁](#0x03-코드-작성-팁)
  - [0x02 표준 입출력](#0x02-표준-입출력-1)
  - [0x03 코드 작성 팁](#0x03-코드-작성-팁-1)
  - [0x02 표준 입출력](#0x02-표준-입출력-2)
  - [0x03 코드 작성 팁](#0x03-코드-작성-팁-2)

<!-- Created by https://github.com/ekalinin/github-markdown-toc -->
<!-- Added by: sungminyou, at: 2022년 6월 28일 화요일 12시 48분 51초 KST -->

<!--te-->

## 0x01 STL과 함수 인자

- 주의 하자(call by value vs call by reference)

  - 단순 변수를 넘길 때(call by value - 복사된 값이 넘어감)

        ```cpp
        void func(int a){
         a = 5;
        }

        int main(){
         int t = 0;
         func(t);
         cout << t << '\n';
        }

        => 출력 0
        ```

- 배열을 넘길 때(call by reference - 주소를 넘김)

  ```cpp
  void func(int arr[]){
   arr[0] = 10;
  }

  int main(){
   int arr[3] = {1, 2, 3};
   func(arr);
   cout << arr[0] << '\n';
  }

  => 출력 10
  ```

- 구조체 넘길 때(call by value - 복사된 값이 넘어감)

  ```cpp
  struct pt {
   int x, y;
  }

  void func(pt a){
   a.x = 10;
  }

  int main(){
   pt tmp = {0, 0};
   func(tmp);
   cout << tmp.x << '\n';
  }

  => 출력 0
  ```

- C++에서 원본을 바꾸는 스킬 with 참조자

  ```cpp
  void swap(int* a, int* b){
   int tmp = *a;
   *a = *b;
   *b = tmp;
  }

  void swap(int& a, int& b){ // 참조자
   int tmp = a;
   a = b;
   b = tmp;
  }

  ```

- STL을 인자로 넘길때?!

  - call by value

    ```cpp
    void func1(vector<int> v){
     v[10] = 7;
    }

    int main(void){
     vector<int> v(100);
     func1(v);
     cout << v[10];
    }
    ```

  - 이러한 사실이 복사를 함으로써 생기는 시간복잡도가 있다!
  - STL역시 참조자를 활용하여 원본의 값을 바꿈과 동시에 의도한 시간복잡도를 구현할 수 있다.

## 0x02 표준 입출력

- 공백을 포함한 문자열을 입력받을 때 scanf나 cin을 이용하면, 공백 앞까지만 입력을 받기때문에 getline() 메소드를 이용하자!
- c++ 과 c의 스트림은 동기화가 되어있기때문에 (cout을 쓰던 printf를 쓰던 상관없이 출력) 그런데 내가 c++의 스트림만 사용할거면 굳이 동기화할 필요가 없으니, `ios::sync_with_stdio(false)` 로 동기화를 해제시켜서 입 / 출력으로 인한 시간초과가 나지않게 하자 대신 동기화를 끊으면 c 스트림과 c++ 스트림을 혼용해서 사용하면 입출력 순서가 의도치 않은대로 꼬일 수 있기 때문에 같이 사용하면 저얼대 안된다.
- `cin.tie(nullptr)` 은 cin을 하기 전 cout 버퍼를 비우는 역할을 하는데, 이것을 해제하는 코드이다. 왜 비울까? cin을 하기 전에 cout의 버퍼에 어떤 내용이 있으면, 출력을 하기도 전에 입력이 되버려서 원하는 순서대로 입력과 출력이 되지 않을 수 있기 때문인데, 채점 서버는 only 출력 값만 보기때문에 굳이 cin 전에 cout 버퍼를 비울 필요가 없어서 `cin.tie(nullptr)` 를 씀으로써 불필요한 과정을 없애는 것이다.
- endl은 개행문자 출력 후 버퍼를 비우는 기능까지 하는 코드인데, 그럴필요가 전혀 없으니 쓰지 말자.

## 0x03 코드 작성 팁

- 개발과 코테는 다르다
- 디버거보단 출력으로 확인
- 문제에서 명시하지 않는 한 출력 맨 마지막 공백 혹은 줄바꿈에 대해 예외처리를 할 필요가 없다.
- 풀이를 적극적으로 찾아보자 한 30분 정도 고민했는데도 실마리가 잡히지 않을 때는 타인의 코드를 보고 배우자## 0x01 STL과 함수 인자

- 주의 하자(call by value vs call by reference)

  - 단순 변수를 넘길 때(call by value - 복사된 값이 넘어감)

        ```cpp
        void func(int a){
         a = 5;
        }

        int main(){
         int t = 0;
         func(t);
         cout << t << '\n';
        }

        => 출력 0
        ```

- 배열을 넘길 때(call by reference - 주소를 넘김)

  ```cpp
  void func(int arr[]){
   arr[0] = 10;
  }

  int main(){
   int arr[3] = {1, 2, 3};
   func(arr);
   cout << arr[0] << '\n';
  }

  => 출력 10
  ```

- 구조체 넘길 때(call by value - 복사된 값이 넘어감)

  ```cpp
  struct pt {
   int x, y;
  }

  void func(pt a){
   a.x = 10;
  }

  int main(){
   pt tmp = {0, 0};
   func(tmp);
   cout << tmp.x << '\n';
  }

  => 출력 0
  ```

- C++에서 원본을 바꾸는 스킬 with 참조자

  ```cpp
  void swap(int* a, int* b){
   int tmp = *a;
   *a = *b;
   *b = tmp;
  }

  void swap(int& a, int& b){ // 참조자
   int tmp = a;
   a = b;
   b = tmp;
  }

  ```

- STL을 인자로 넘길때?!

  - call by value

    ```cpp
    void func1(vector<int> v){
     v[10] = 7;
    }

    int main(void){
     vector<int> v(100);
     func1(v);
     cout << v[10];
    }
    ```

  - 이러한 사실이 복사를 함으로써 생기는 시간복잡도가 있다!
  - STL역시 참조자를 활용하여 원본의 값을 바꿈과 동시에 의도한 시간복잡도를 구현할 수 있다.

## 0x02 표준 입출력

- 공백을 포함한 문자열을 입력받을 때 scanf나 cin을 이용하면, 공백 앞까지만 입력을 받기때문에 getline() 메소드를 이용하자!
- c++ 과 c의 스트림은 동기화가 되어있기때문에 (cout을 쓰던 printf를 쓰던 상관없이 출력) 그런데 내가 c++의 스트림만 사용할거면 굳이 동기화할 필요가 없으니, `ios::sync_with_stdio(false)` 로 동기화를 해제시켜서 입 / 출력으로 인한 시간초과가 나지않게 하자 대신 동기화를 끊으면 c 스트림과 c++ 스트림을 혼용해서 사용하면 입출력 순서가 의도치 않은대로 꼬일 수 있기 때문에 같이 사용하면 저얼대 안된다.
- `cin.tie(nullptr)` 은 cin을 하기 전 cout 버퍼를 비우는 역할을 하는데, 이것을 해제하는 코드이다. 왜 비울까? cin을 하기 전에 cout의 버퍼에 어떤 내용이 있으면, 출력을 하기도 전에 입력이 되버려서 원하는 순서대로 입력과 출력이 되지 않을 수 있기 때문인데, 채점 서버는 only 출력 값만 보기때문에 굳이 cin 전에 cout 버퍼를 비울 필요가 없어서 `cin.tie(nullptr)` 를 씀으로써 불필요한 과정을 없애는 것이다.
- endl은 개행문자 출력 후 버퍼를 비우는 기능까지 하는 코드인데, 그럴필요가 전혀 없으니 쓰지 말자.

## 0x03 코드 작성 팁

- 개발과 코테는 다르다
- 디버거보단 출력으로 확인
- 문제에서 명시하지 않는 한 출력 맨 마지막 공백 혹은 줄바꿈에 대해 예외처리를 할 필요가 없다.
- 풀이를 적극적으로 찾아보자 한 30분 정도 고민했는데도 실마리가 잡히지 않을 때는 타인의 코드를 보고 배우자## 0x01 STL과 함수 인자

- 주의 하자(call by value vs call by reference)

  - 단순 변수를 넘길 때(call by value - 복사된 값이 넘어감)

        ```cpp
        void func(int a){
         a = 5;
        }

        int main(){
         int t = 0;
         func(t);
         cout << t << '\n';
        }

        => 출력 0
        ```

- 배열을 넘길 때(call by reference - 주소를 넘김)

  ```cpp
  void func(int arr[]){
   arr[0] = 10;
  }

  int main(){
   int arr[3] = {1, 2, 3};
   func(arr);
   cout << arr[0] << '\n';
  }

  => 출력 10
  ```

- 구조체 넘길 때(call by value - 복사된 값이 넘어감)

  ```cpp
  struct pt {
   int x, y;
  }

  void func(pt a){
   a.x = 10;
  }

  int main(){
   pt tmp = {0, 0};
   func(tmp);
   cout << tmp.x << '\n';
  }

  => 출력 0
  ```

- C++에서 원본을 바꾸는 스킬 with 참조자

  ```cpp
  void swap(int* a, int* b){
   int tmp = *a;
   *a = *b;
   *b = tmp;
  }

  void swap(int& a, int& b){ // 참조자
   int tmp = a;
   a = b;
   b = tmp;
  }

  ```

- STL을 인자로 넘길때?!

  - call by value

    ```cpp
    void func1(vector<int> v){
     v[10] = 7;
    }

    int main(void){
     vector<int> v(100);
     func1(v);
     cout << v[10];
    }
    ```

  - 이러한 사실이 복사를 함으로써 생기는 시간복잡도가 있다!
  - STL역시 참조자를 활용하여 원본의 값을 바꿈과 동시에 의도한 시간복잡도를 구현할 수 있다.

## 0x02 표준 입출력

- 공백을 포함한 문자열을 입력받을 때 scanf나 cin을 이용하면, 공백 앞까지만 입력을 받기때문에 getline() 메소드를 이용하자!
- c++ 과 c의 스트림은 동기화가 되어있기때문에 (cout을 쓰던 printf를 쓰던 상관없이 출력) 그런데 내가 c++의 스트림만 사용할거면 굳이 동기화할 필요가 없으니, `ios::sync_with_stdio(false)` 로 동기화를 해제시켜서 입 / 출력으로 인한 시간초과가 나지않게 하자 대신 동기화를 끊으면 c 스트림과 c++ 스트림을 혼용해서 사용하면 입출력 순서가 의도치 않은대로 꼬일 수 있기 때문에 같이 사용하면 저얼대 안된다.
- `cin.tie(nullptr)` 은 cin을 하기 전 cout 버퍼를 비우는 역할을 하는데, 이것을 해제하는 코드이다. 왜 비울까? cin을 하기 전에 cout의 버퍼에 어떤 내용이 있으면, 출력을 하기도 전에 입력이 되버려서 원하는 순서대로 입력과 출력이 되지 않을 수 있기 때문인데, 채점 서버는 only 출력 값만 보기때문에 굳이 cin 전에 cout 버퍼를 비울 필요가 없어서 `cin.tie(nullptr)` 를 씀으로써 불필요한 과정을 없애는 것이다.
- endl은 개행문자 출력 후 버퍼를 비우는 기능까지 하는 코드인데, 그럴필요가 전혀 없으니 쓰지 말자.

## 0x03 코드 작성 팁

- 개발과 코테는 다르다
- 디버거보단 출력으로 확인
- 문제에서 명시하지 않는 한 출력 맨 마지막 공백 혹은 줄바꿈에 대해 예외처리를 할 필요가 없다.
- 풀이를 적극적으로 찾아보자 한 30분 정도 고민했는데도 실마리가 잡히지 않을 때는 타인의 코드를 보고 배우자

**본 내용은 바킹독님의 유튜브 실전 코딩테스트 강의의 내용을 기반으로 제작되었습니다**
