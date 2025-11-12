from math import gcd

LIMIT = 60
cache = [[0] * (LIMIT + 1) for _ in range(LIMIT + 1)]


def solution(a: int, b: int) -> int:
    if cache[a][b]:
        return cache[a][b]
    if a == b:
        res =  1
    elif a > b:
        res = solution(a - b, b) * 2
    else:
        res = solution(b, a) + 1
    cache[a][b] = res
    return res


def main():
    while True:
        try:
            a, b = map(int, input().split())
            g = gcd(a, b)
            a //= g
            b //= g
            print(solution(a, b))
        except EOFError:
            break


main()
