#include <iostream>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long n;
    if (!(cin >> n)) return 0;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    unsigned long long left = 1, right = n;
    unsigned long long ans = right;

    while (left <= right) {
        unsigned long long mid = left + (right - left) / 2;

        if (mid >= (n + mid - 1) / mid) { 
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}