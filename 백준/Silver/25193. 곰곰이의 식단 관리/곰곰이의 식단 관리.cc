#include <iostream>
using namespace std;

int main() 
{
    int N = 0, chickenCnt = 0, notChickenCnt = 0;
    string S = "";
    cin >> N >> S;
    for(int i = 0; i < N; i++){
      if(S[i] == 'C')
        chickenCnt++;
      else notChickenCnt++;
    }
    if (chickenCnt % (notChickenCnt+1) != 0)
      cout << chickenCnt / (notChickenCnt+1) +1;
	  else cout << chickenCnt / (notChickenCnt + 1);

    return 0;
}