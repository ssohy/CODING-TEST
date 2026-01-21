#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
    int N = 0, K = 0, sum = 0;
    cin >> N >> K;
    vector<int> arr(N), sortArr(N), selectNum;
    for(int i = 0; i < N; i++){
      cin >> arr[i];
      sortArr[i] = arr[i];
    }
    sort(sortArr.rbegin(), sortArr.rend());
    
    for(int i = 0; i < K; i++){
      sum += sortArr[i];
    }
    sum -= K * (K-1) / 2;
    cout << sum << '\n';
    return 0;
}