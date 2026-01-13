#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> arr;
int A, P;
bool isEnd;

void nextNum(int curNum)
{
  int n_1 = curNum, result = 0;
  while(n_1 != 0){
    result += pow(n_1 % 10, P);
    n_1 /= 10;
  }
  auto it = find(arr.begin(), arr.end(), result);
  if(it == arr.end())
    arr.push_back(result);
  else{
    isEnd = true;
    int size = arr.size();
    for(int i = it - arr.begin(); i < size; i++){
      arr.pop_back();
    }
  }

}


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int curNum = 0;

    cin >> A >> P;
    
    arr.push_back(A);
    
    while(!isEnd){
      nextNum(arr[arr.size()-1]);
    }
    cout << arr.size() << '\n';
    return 0;
}