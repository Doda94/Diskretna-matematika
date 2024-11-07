MAX_N = 15000

def polinomi(a, b, size_a, size_b):
    result = [0] * (MAX_N*2 + 1)
    for i in range(min(size_a, MAX_N)):
        for j in range(min(size_b, MAX_N)):
            result[i + j] += a[i] * b[j]
    return result

def sol(a, b, c, d, e, n):
    a = n if (a == -1 or a > n) else a
    b = n if (b == -1 or b > n) else b
    c = n if (c == -1 or c > n) else c
    d = n if (d == -1 or d > n) else d
    e = n if (e == -1 or e > n) else e

    A = [1] * (min(a + 1, MAX_N + 1))
    B = [1] * (min(b + 1, MAX_N + 1))
    C = [1] * (min(c + 1, MAX_N + 1))
    D = [1] * (min(d + 1, MAX_N + 1))
    E = [1] * (min(e + 1, MAX_N + 1))

    temp = polinomi(A, B, a + 1, b + 1)
    R = polinomi(temp, C, a + b + 1, c + 1)
    temp = polinomi(R, D, a + b + c + 1, d + 1)
    R = polinomi(temp, E, a + b + c + d + 1, e + 1)

    return R[n]

def main():
    print("Unesite broj vrecica caja Bohea (parameter a):", end=" ")
    a = int(input())
    print("Unesite broj vrecica caja Congo  (parameter b):", end=" ")
    b = int(input())
    print("Unesite broj vrecica caja Souch gs (parameter c):", end=" ")
    c = int(input())
    print("Unesite broj vrecica caja Singl  (parameter d):", end=" ")
    d = int(input())
    print("Unesite broj vrecica caja Hyson (parameter e):", end=" ")
    e = int(input())
    print("Unesite broj n:", end=" ")
    n = int(input())

    result = sol(a, b, c, d, e, n)
    print(f"Gradjani bostona mogu napraviti {result} razlicitih cajanki.")

if __name__ == "__main__":
    main()