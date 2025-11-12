def prime_factor_sum(num: int) -> int:
    def helper(p: int):
        nonlocal result, num
        while num % p == 0:
            result += p
            num //= p

    result = 0
    helper(2)
    helper(3)
    for i in range(5, int(num**0.5) + 1, 6):
        helper(i)
        helper(i + 2)
    
    if num > 1:
        result += num
    return result


def main():
    while True:
        try:
            print(prime_factor_sum(int(input())))
        except EOFError:
            break


if __name__ == '__main__':
    main()
