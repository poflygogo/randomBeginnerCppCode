from typing import List # 這個弄不弄都無所謂，我只是想要 type hint


SPACE = " "
TOKEN = "*"
ROW_SIGN = "-"
COL_SIGN = "|"


def gild_the_lily(size: int, m: int) -> List[List[str]]:
    # initialize
    arr = [[COL_SIGN] + [SPACE] * size + [COL_SIGN] for _ in range(size + 2)]
    arr[0] = arr[-1] = [ROW_SIGN] * (size + 2)

    x1, y1 = map(int, input().split())
    for _ in range(m - 1):
        x2, y2 = map(int, input().split())

        if x1 == x2:
            step = 1 if y1 <= y2 else -1
            for c in range(y1, y2 + step, step):
                arr[x1][c] = TOKEN
        else:
            step = 1 if x1 <= x2 else -1
            for r in range(x1, x2 + step, step):
                arr[r][y1] = TOKEN

        x1, y1 = x2, y2

    return arr


def main():
    while True:
        try:
            n, m = map(int, input().split())
            print("\n".join("".join(line) for line in gild_the_lily(n, m)))
        except ValueError:  # 幹你娘有多餘空行啦
            continue
        except EOFError:
            break


if __name__ == "__main__":
    main()
