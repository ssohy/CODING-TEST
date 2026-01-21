#include <iostream>
using namespace std;

int main() 
{
    int n = 0;
    int dp[1000];
    dp[0] = 1;
    dp[1] = 3;
    cin >> n;
    
    for(int i = 2; i < n; i++){
      dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
    }
    
    cout << dp[n-1] << '\n';
    return 0;
}