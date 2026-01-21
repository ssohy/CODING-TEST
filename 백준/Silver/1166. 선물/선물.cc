#include <iostream>
using namespace std;

int main() 
{
    int N = 0, L = 0, W = 0, H = 0;
    long double left = 0, right = 1000000000, mid;
    cin >> N >> L >> W >> H;
    
    for(int i = 0; i < 10000; i++){
      mid = (left+right) / 2;
      if((long long)(L / mid) * (long long)(W/mid) * (long long)(H/mid) < N) right = mid;
      else left = mid;
    }
    cout << fixed;
    cout.precision(10);
    cout << left << '\n';
    return 0;
}