#include <iostream>
#include <vector>
using namespace std;
vector<string> dancing;
int result = 1;

void isDancing(string name1, string name2)
{
  bool isExist1 = false, isExist2 = false;
  for(int j = 0; j < dancing.size(); j++){
    if(name1 == dancing[j]){
      isExist1 = true;
    }
    if(name2 == dancing[j]){
      isExist2 = true;
    }
    if(isExist1 && isExist2) break;
  }
  if(isExist1 == false && isExist2 == true){
    result++;
    dancing.push_back(name1);
  }
  else if(isExist1 == true && isExist2 == false){
    result++;
    dancing.push_back(name2);
  }
}


int main() 
{
    int N = 0;
    string p1 = "", p2 = "";
    cin >> N;
    
    dancing.push_back("ChongChong");
    for(int i = 0; i < N; i++){
      cin >> p1 >> p2;
      isDancing(p1, p2);
    }
    
    cout << result << '\n';
    return 0;
}