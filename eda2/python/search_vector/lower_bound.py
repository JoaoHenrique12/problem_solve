def lower_bound(x:int,lst:list):
    lo, up = 0,len(lst)
    ans = -1
    while lo < up:
        mid = (lo + up)//2
        if lst[mid] >= x:
            ans = mid
            up = mid - 1
        else:
            lo = mid + 1
    return ans

nums = [1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7]

print(f"{lower_bound(2,nums)}")
