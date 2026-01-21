#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    cin >> N;
    vector<int> arr(N);
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // next_permutation: arr를 다음 순열로 바꾸고 true 반환
    // 만약 현재가 마지막 순열이라면 false 반환
    if (next_permutation(arr.begin(), arr.end())) {
        for(int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
    } else {

        cout << -1 << "\n";
    }

    return 0;
}