#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0, a = 1, b = 2; 
    cin >> n;
    if (n == 1) { 
      cout << 1 << '\n'; 
      return 0; 
      
    }

    for (int i = 3; i <= n; i++) {
        int c = (a + b) % 10007;
        a = b; b = c;
    }
    cout << b % 10007 << '\n';
    return 0;
}