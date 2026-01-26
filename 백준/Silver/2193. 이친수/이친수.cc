#include <iostream>
using namespace std;

int main() 
{
    int n = 0;
    long long dp[91];
    
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 1;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << dp[n] << endl;
    return 0;
}