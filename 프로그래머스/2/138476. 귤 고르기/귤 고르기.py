from collections import Counter
def solution(k, tangerine):
    answer, curCnt = 0, 0
    tangerine.sort()
    
    maxCounts = Counter(tangerine).most_common()
    for size, cnt in maxCounts:
        if curCnt < k:
            answer += 1
            curCnt += cnt
    return answer