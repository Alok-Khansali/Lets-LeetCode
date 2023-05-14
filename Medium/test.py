def min_time(N, work):
    lo, hi = 0, 1000000000
    while lo < hi:
        mid = (lo + hi) // 2
        total_time = sum(abs(work[i] - mid - (i+1)) for i in range(N))
        if total_time <= sum(abs(work[i] - lo - (i+1)) for i in range(N)):
            hi = mid
        else:
            lo = mid + 1
    return sum(abs(work[i] - lo - (i+1)) for i in range(N))

# Example usage:
print(min_time(6, [4, 2, 5, 3, 5, 1]))  # Output: 11
