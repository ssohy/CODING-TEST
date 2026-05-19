#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int timeToSec(string time_str) { // 문자열->초 단위 정수로
    int h = stoi(time_str.substr(0, 2));
    int m = stoi(time_str.substr(3, 2));
    int s = stoi(time_str.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

string secToTime(int total_sec) {// 초 단위 정수->문자열로
    int h = total_sec / 3600;
    int m = (total_sec % 3600) / 60;
    int s = total_sec % 60;
    
    string ret = "";
    if (h < 10) ret += "0";
    ret += to_string(h) + ":";
    if (m < 10) ret += "0";
    ret += to_string(m) + ":";
    if (s < 10) ret += "0";
    ret += to_string(s);
    
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int play_sec = timeToSec(play_time); // 정수로
    int adv_sec = timeToSec(adv_time); // 정수로
    vector<long long> total_time(play_sec + 1, 0); // 영상 총 길이

    for (string log : logs) {
        int start_sec = timeToSec(log.substr(0, 8)); // 시작 시간
        int end_sec = timeToSec(log.substr(9, 8)); // 끝나는 시간
        total_time[start_sec]++;
        total_time[end_sec]--;
    }

    for (int i = 1; i <= play_sec; i++) { // 각 초의 동시 시청자 수 계산
        total_time[i] += total_time[i - 1];
    }
    for (int i = 1; i <= play_sec; i++) { // 0초부터 해당 시각까지의 누적 시청시간 계산
        total_time[i] += total_time[i - 1];
    }

    long long max_sum = total_time[adv_sec - 1];
    int max_start_time = 0;
    
    for (int i = 1; i <= play_sec - adv_sec; i++) {
        long long current_sum = total_time[i + adv_sec - 1] - total_time[i - 1];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_start_time = i;
        }
    }
    return secToTime(max_start_time);
}