# lo = mid + 1 pois mid ja foi comparado.


def binary_search(x: int, lst: list):
    lo, up = 0, len(lst) - 1
    while lo < up:
        mid = (lo + up) // 2
        if x == lst[mid]:
            return mid
        elif x < lst[mid]:
            up = mid - 1
        else:
            lo = mid + 1
    return -1


nums = [1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7]

print(f"{binary_search(2,nums)}")
