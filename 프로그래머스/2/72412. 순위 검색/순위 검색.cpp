#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<int>> infoMap;

void makeCombinations(vector<string>& tokens, int score, string key, int depth) {
    if (depth == 4) {
        infoMap[key].push_back(score);
        return;
    }
    makeCombinations(tokens, score, key + tokens[depth], depth + 1);
    makeCombinations(tokens, score, key + "-", depth + 1);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    infoMap.clear();

    for (string in : info) {
        stringstream ss(in);
        vector<string> tokens(4);
        int score;
        ss >> tokens[0] >> tokens[1] >> tokens[2] >> tokens[3] >> score;
        makeCombinations(tokens, score, "", 0);
    }
    for (auto& pair : infoMap) {
        sort(pair.second.begin(), pair.second.end());
    }
    for (string q : query) {
        stringstream ss(q);
        string lan, and1, pos, and2, perHis, and3, food;
        int targetScore;
        ss >> lan >> and1 >> pos >> and2 >> perHis >> and3 >> food >> targetScore;

        string queryKey = lan + pos + perHis + food;

        if (infoMap.find(queryKey) != infoMap.end()) {
            vector<int>& scores = infoMap[queryKey];
            auto iter = lower_bound(scores.begin(), scores.end(), targetScore);
            answer.push_back(scores.end() - iter);
        } else {
            answer.push_back(0);
        }
    }

    return answer;
}