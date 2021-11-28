# Learing About

## 특수기호 문자열에 삽입하는 법

+ \t : 수평 tab tab(8)칸 띄우기
+ \n : 개행 커서를 한줄 밑으로 이동(enter와 같은효과)
+ \' : '(쿼티션)을 표시 , 단독으로 '입력시 화면에 출력 x
+ \" : "(더블 쿼티션) 표시
+ \\ : \(역슬래시 표시)

## getline 메서드

```cpp
string input;
getline(cin, input);
```

## 홀 짝 판단 비트연산식

+ 어떤 숫자와 1을 비트연산으로 비교하여 홀수인 경우는 1 , 짝수일 경우는 0이 나온다.
+ 왜냐하면 홀수를 비트스트링으로 나타내면 RSD는 항상 1이기 때문이다. 그래서 1과 &연산을 시키면 RSD가 1이 나온다. 
+ 1은 0...01이기때문에 앞자리 비트는 다 0이된다

```cpp
int i = 100;
if(i&1) cout << '홀수';
else cout << '짝수';
```

## next_permutation

+ STL에 algorithm 헤더파일을 추가하면(#include <algorithm>) 다음 아래 함수를 통해서 순열을 구할수가 있다.
+ 오름차순으로 정렬된 값을 가진 컨테이너로만 사용가능합니다.
+ default로 operator < 를 사용해 순열을 생성합니다. 즉 오름차순으로 순열을 생성합니다. 
+ 중복이 있는 원소들은 중복을 제외하고 순열을 만들어줍니다. 

```cpp
next_permutation(v.begin(), v.end());
```
### 순열의 응용 - 조합(Combination) 구하기
 

+ 배열 s의 n개의 원소 중에서 r개의 원소를 택하는 방법은 다음과 같습니다. 
+ 우선 크기가 n인 배열 temp를 만들어 r개의 원소는 1로, (n-r)개의 원소는 0으로 초기화합니다. 
+ temp의 모든 순열을 구합니다. 
+ temp의 순열에서 원소값이 1인 인덱스만 배열 s에서 가져옵니다. 

## 역으로 뒤집는 함수 reverse

```cpp
// begin부터 end - 1까지 뒤집기에 포함됨!! 주의 end는 미포함임
reverse(v.begin(), v.end());

```

## 최대 / 최소 찾는 max_element, min_element

+ 최대값을 찾는다.

```cpp
cout << *max_element(a, a + 9) << '\n'; // max_element는 주소를 반환하기에 그 값을 참조하기 위해서는 참조연산자 *를 붙여야함
cout << max_element(a, a + 9) - a + 1; // 주소값 - 시작주소값을빼면 index나온다! 
```