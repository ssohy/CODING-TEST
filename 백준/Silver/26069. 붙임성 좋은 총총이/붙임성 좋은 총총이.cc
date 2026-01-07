#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    set<string> dancing;
    dancing.insert("ChongChong");

    string p1, p2;
    for(int i = 0; i < N; i++) {
        cin >> p1 >> p2;
        if (dancing.count(p1) || dancing.count(p2)) {
            dancing.insert(p1);
            dancing.insert(p2);
        }
    }

    cout << dancing.size() << '\n';

    return 0;
}