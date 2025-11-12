def solution(a: int, b: int) -> int:
    if a == b:
        return 1
    elif a > b:
        return solution(a - b, b) * 2
    else:
        return solution(b, a) + 1
    

def main():
    while True:
        try:
            a, b = map(int, input().split())
            print(solution(a, b))
        except EOFError:
            break


main()
