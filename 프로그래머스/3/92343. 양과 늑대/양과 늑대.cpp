#include <vector>
#include <algorithm>

using namespace std;

void dfs(int cur, int sheep, int wolf, vector<int> next_nodes, 
         const vector<int>& info, const vector<vector<int>>& graph, int& max_sheep) {
    
    // 현재 노드에 양이 있는지 늑대가 있는지 확인하여 카운트 증가
    if (info[cur] == 0) {
        sheep++;
    } else {
        wolf++;
    }
    
    // 늑대의 수가 양의 수와 같거나 많아지면 탐색 종료(잡아먹힘)
    if (wolf >= sheep) {
        return;
    }
    max_sheep = max(max_sheep, sheep); // 최대 양의 수 갱신
    vector<int> next_visit = next_nodes; // 다음으로 방문할 수 있는 노드 목록 구성
    
    // 현재 노드는 방문했으므로 목록에서 제거
    next_visit.erase(find(next_visit.begin(), next_visit.end(), cur));
    
    for (int child : graph[cur]) { // 현재 노드의 자식 노드들을 방문 가능 목록에 추가
        next_visit.push_back(child);
    }
    for (int next_node : next_visit) { // 방문 가능한 노드들을 깊이 우선 탐색(DFS)
        dfs(next_node, sheep, wolf, next_visit, info, graph, max_sheep);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    vector<vector<int>> graph(n);
    int max_sheep = 0;
    for (const auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    vector<int> initial_nodes = {0};
    dfs(0, 0, 0, initial_nodes, info, graph, max_sheep);
    
    return max_sheep;
}