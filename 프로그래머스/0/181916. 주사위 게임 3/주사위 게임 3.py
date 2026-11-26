def solution(a, b, c, d):
    nums = sorted([a,b,c,d])
    if nums[0] == nums[3]: # 4개 같음
        return 1111 * nums[0]
    elif nums[0] == nums[2]: # 3개 같음
        return (10 * nums[0] + nums[3]) ** 2
    elif nums[1] == nums[3]:
        return (10 * nums[3] + nums[0]) ** 2
    elif nums[0] == nums[1] and nums[2] == nums[3]: # 2개 같음
        return (nums[0] + nums[2]) * abs(nums[0] - nums[2])
    elif nums[0] == nums[1]:  # 앞 2개만 같음
        return nums[2] * nums[3]
    elif nums[1] == nums[2]:  # 중간 2개만 같음
        return nums[0] * nums[3]
    elif nums[2] == nums[3]:  # 뒤 2개만 같음
        return nums[0] * nums[1]
    else: # 다 다름
        return nums[0]