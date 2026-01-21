#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> arr,resultArr;

void dfs()
{
  if(resultArr.size() == M){
    for(int i = 0; i < M; i++){
      cout << resultArr[i] << (i < M - 1 ? ' ' : '\n');
    }  
    return;
  }
  for(int i = 0; i < N; i++){
   // if(resultArr.empty() || resultArr.back() <= arr[i]){
      resultArr.push_back(arr[i]);
      dfs();
      resultArr.pop_back();
   // }
  }
}
int main() 
{
    int tmp = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
      cin >> tmp;
      arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    dfs();
    return 0;
}