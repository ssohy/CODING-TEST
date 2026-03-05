#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<string ,int>> stringNum;
string nums[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void transitos(int n)
{
  string number = "";
  int one = n % 10, ten = n / 10;
  if(ten != 0){
    number = nums[ten] + " ";
  }
  number += nums[one];
  
  stringNum.push_back({number, n});
}

int main() 
{
    int M = 0, N = 0;

    cin >> M >> N;
    for(int i = M; i <= N; i++){
      transitos(i);
    }
    sort(stringNum.begin(), stringNum.end());
    
    
    for(int i = 0; i < stringNum.size(); i++){
      cout << stringNum[i].second << " ";
      if(i % 10 == 9) cout << '\n';
    }
    return 0;
}