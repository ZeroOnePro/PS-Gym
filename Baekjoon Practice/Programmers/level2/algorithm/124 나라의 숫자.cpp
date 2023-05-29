/* 효율성 통과 못함
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int num[3] = {1,2,4};
vector<int> selected(15,0);
string answer = "";
int call = 0;
void permutation(int digit, int length, int cnt,int option){
    bool flag = false;
    if(flag) return;
    if(digit == length){
        if(call == cnt) {
            flag = true;
            for(int i=0; i<length; ++i ) {
                answer += to_string(selected[i]);
            }
        }
         call+=1;
        return;
    }
   if(option == 1){
        for(int i=0; i<3; ++i){
           selected[digit] = num[i];
           permutation(digit+1,length, cnt,1);
        }
   }
    if(option == 2){
        for(int i=3; i>=0; --i){
           selected[digit] = num[i];
           permutation(digit+1,length, cnt,2);
        }
    }

}
int sequence(int digit){
    int sum = 0;
    sum += (int)pow(3,digit)  -1;
    sum *= 9;
    sum /= 2;
    sum += 3;
    return sum;
}
string solution(int n) {
    string ans = "";
    int digit = 0;
    int start_bin = 0;
    // 자리 수 구하는 로직
    while(1){
        if(sequence(digit) >= n) {
            break;
        }else{
            digit += 1;
        }
    }
    start_bin = sequence(digit-1)+ 1;
    int end_bin = sequence(digit);
    digit += 1;
    if(digit >= 2) {
        if((end_bin - start_bin) / 2 <= n){
            permutation(0,digit,n-start_bin,1);
        }else{
             permutation(0,digit,end_bin-n,2);
        }
        ans += answer;
    }else{
        int m = n % 3;
        switch(m){
            case 0:
                ans += "4";
                break;
            case 1:
                ans+= "1";
                break;
            case 2:
                ans += "2";
                break;
        }
    }
    return ans;
}
*/

/* 진법 변환
10진수의 수를 2로 나누어 가며 그 나머지를 맨 오른쪽 수로 미루면서 왼쪽으로
진행한다. 3진법도 위와 마찬가지로 3으로 나누면서 그 나머지를 해당 자리수로
채울수 있다. 그러나 124 나라에서 원하는건 원래 3진법에서 사용하는 0,1,2 대신
1,2,4 를 사용하는 것이다. 그래서 '124'를 두고 3으로 나눈 나머지의 인덱스값을 각
자리수로 사용하는 것이다.
*/

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
  string answer = "";
  int tmp = 0;
  while (n > 0) {
    tmp = n % 3;
    tmp == 0 ? n = (n / 3) - 1 : n /= 3;
    answer = "412"[tmp] + answer;
  }
  return answer;
}