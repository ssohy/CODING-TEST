#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    string str1 = "", str2 = "";
    cin >> str1 >> str2;
    int str1Size = str1.size();
    int str2Size = str2.size();
    vector<vector<int>> dp(str1Size+1, vector<int>(str2Size+1, 0));
    
    for(int i = 1; i <= str1Size; i++){
      for(int j = 1; j <= str2Size; j++){
        if(str1[i-1] == str2[j-1]){
          dp[i][j] = dp[i-1][j-1] + 1;
        }else{
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }
    
    cout << dp[str1Size][str2Size] << '\n';
    return 0;
}