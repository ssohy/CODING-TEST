#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int min = 2e9;
    int max = -2e9;
    string answer = "";
    for(int i = 0; i < s.length(); i++){
        string curNum;
        if(s[i] == ' ') continue;
        while(s[i] != ' '){
            curNum += s[i];
            i++;
        }
        int num = stoi(curNum);
        if(min > num) min = num;
        if(max < num) max = num;
    }
    answer = (to_string(min) + ' ' + to_string(max));
    return answer;
}