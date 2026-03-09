#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int T = 0, N = 0;
    while(true){
      cin >> N;
      if(N == 0) break;
      float maxHeight = 0, curHeight = 0;
      string maxName = "", curName = "";
      vector<string> maxNames;
      for(int i = 0; i < N; i++){
        cin >> curName >> curHeight;
        if(curHeight > maxHeight){
          maxHeight = curHeight;
          maxName = curName;
          maxNames.clear();
        } else if(curHeight == maxHeight){
          if(maxNames.size() == 0){
            maxNames.push_back(maxName);
            maxNames.push_back(curName);
          }else{
            maxNames.push_back(curName);
          }
        }
      }
      
      if(maxNames.size() != 0){
        for(int i = 0; i < maxNames.size(); i++){
         cout << maxNames[i] << " ";
        }
      }else cout << maxName << '\n';
    }
    

    return 0;
}