/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> seq(n, 0);
        for (int i = 0; i < n; ++i) {
                cin >> seq[i];
        }
        sort(seq.begin(), seq.end());
        int big_num = 0;
        bool change = true;
        for (int i = 1; i <= m; ++i) {
                if (change) {
                        big_num += seq[n - 1];
                        if (!(i % k)) change = false;
                }
                else {
                        big_num += seq[n - 2];
                        change = true;
                }
        }
        cout << big_num << '\n';
        return 0;
}
*/