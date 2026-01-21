#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long X = 0, Y = 0, curZ = 0, left = 0, right = 1000000000, mid = 0, result = 0;
    
    cin >> X >> Y;
    
    curZ = Y * 100 / X;
    if(curZ >= 99){
      cout << -1 << '\n';
      return 0;
    }
    
    
    while(left <= right){
      mid = (left + right) / 2;
      long long newZ = (Y + mid) * 100 / (X + mid);
      if(curZ < newZ){
        result = mid;
        right = mid - 1;
      }else{
        left = mid + 1;
      }
    }
    cout << result << '\n';
    return 0;
}