#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N = 0, X = 0;
    cin >> N;
    while(N--){
      cin >> X;
      long long num = sqrt(X);
      if(num * num == X) cout << 1 << " ";
      else cout << 0 << " ";
    }
    return 0;
}