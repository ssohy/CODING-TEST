#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int minMove = n - 1;

    for (int i = 0; i < n; i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++;
        }
        minMove = min(minMove, i + n - next + min(i, n - next));
    }

    return answer + minMove;
}