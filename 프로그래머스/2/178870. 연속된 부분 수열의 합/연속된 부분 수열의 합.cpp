#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int right = 0, left = 0;
    int curSum = 0, minLen = sequence.size() + 1;

    for (left = 0; left < sequence.size(); left++) {
        curSum += sequence[left];

        while (curSum > k && right <= left) {
            curSum -= sequence[right];
            right++;
        }

        if (curSum == k) {
            int curLen = left - right;
            if (curLen < minLen) { 
                minLen = curLen;
                answer[0] = right;
                answer[1] = left;
            }
        }
    }

    return answer;
}