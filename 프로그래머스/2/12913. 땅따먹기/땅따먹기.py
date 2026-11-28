def solution(land):
    answer = 0
    for i in range(1, len(land)):
        for j in range(4):
            land[i][j] += max(land[i-1][:j] + land[i-1][j+1:]) # 현재 열은 제외하고 나머지 열들 최대값 더하기
    return max(land[-1])