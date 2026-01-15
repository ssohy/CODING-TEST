#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int T = 0;
    cin >> T;
    
    while (T--) {
      int N = 0, M = 0, tmp = 0, result = 1, curMaxIdx = 0;
      queue<int> importance;
      vector<int> priority;
      cin >> N >> M;
      
      for(int i = 0; i < N; i++){
        cin >> tmp;
        importance.push(tmp);
        priority.push_back(tmp);
      }
      
      sort(priority.rbegin(), priority.rend());
      
      while (!importance.empty()) {
        int maxValue = priority[curMaxIdx];
        
        if(maxValue == importance.front()){
          importance.pop();
          if(M == 0){
            cout << result << '\n';
            break;
          }else{
            result++;
            M--;
            curMaxIdx++;
          }
        }else{
          importance.push(importance.front());
          importance.pop();
          M = (M - 1 + importance.size()) % importance.size();
        }
      }
    }
    return 0;
}