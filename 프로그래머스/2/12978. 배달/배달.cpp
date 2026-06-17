#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    // graph[출발마을] = { {도착마을, 비용}, {도착마을, 비용}, ... }
    vector<vector<pair<int, int>>> graph(N + 1);
    // {누적 비용, 마을 번호}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 최단거리
    vector<int> dist(N + 1, INF);
    
    
    for (const auto& r : road) {
        int u = r[0];
        int v = r[1];
        int w = r[2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    // 시작점
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int current_cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        // 이미 처리된 적 O && 지금 꺼낸 비용보다 더 짧은 경로 존재하면 패스
        if (dist[current] < current_cost) continue;
        
        // 현재 마을이랑 연결된 다른 이웃 마을 확인
        for (const auto& neighbor : graph[current]) {
            int next = neighbor.first;
            int next_cost = current_cost + neighbor.second;
            
            // 더 짧은 경로를 발견한 경우
            if (next_cost < dist[next]) {
                dist[next] = next_cost;
                pq.push({next_cost, next});
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) {
            answer++;
        }
    }
    return answer;
}