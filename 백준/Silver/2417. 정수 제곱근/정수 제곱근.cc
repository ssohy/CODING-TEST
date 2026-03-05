#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull n;
    if (!(cin >> n)) return 0;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    ull left = 1, right = 3037000500ULL; // sqrt(2^64) 근처값으로 제한
    ull ans = right;

    while (left <= right) {
        ull mid = left + (right - left) / 2;

        // mid * mid >= n 을 체크 (오버플로우 방지)
        // mid가 충분히 커서 mid >= n / mid 이면 mid*mid >= n 일 가능성이 높음
        if (mid >= (n + mid - 1) / mid) { 
            ans = mid;         // 조건 만족하는 q 후보 저장
            right = mid - 1;   // 더 작은 q가 있는지 왼쪽 탐색
        } else {
            left = mid + 1;    // 조건 만족 못하므로 오른쪽 탐색
        }
    }

    cout << ans << '\n';
    return 0;
}