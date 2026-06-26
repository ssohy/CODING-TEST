import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        Arrays.sort(routes, (o1, o2) -> o1[0] - o2[0]);
        
        for(int i = 0; i < routes.length; i++){
            int limit = routes[i][1];
            answer++;
            while (i + 1 < routes.length && routes[i + 1][0] <= limit) {
                i++;
                limit = Math.min(limit, routes[i][1]);
            }
        }
        return answer;
    }
}