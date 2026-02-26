def solve():
    m = int(input())
    a = set(map(int, input().split()))
    n = int(input())
    b = set(map(int, input().split()))

    symmetric_difference = a.symmetric_difference(b)
    
    sorted_symmetric_difference = sorted(list(symmetric_difference))
    
    for num in sorted_symmetric_difference:
        print(num)

solve()
