# String

>   `C++ 에서도 람다식을 쓸 수 있다!`

```
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n = s.size();
    vector<int> a;
    for (int i=0; i<n; i++) a.push_back(i);
    sort(a.begin(),a.end(), [&s](int u, int v) {
        return strcmp(s.c_str()+u,s.c_str()+v) < 0;
    }); => lambda expression in c++
    for (auto &x : a) {
        cout << s.substr(x) << '\n';
    }
    return 0;
}

```