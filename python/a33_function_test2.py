def print_n_times(*value, n = 2):
    print(type(value))
    for _ in range(n):
        for ele in value:
            print(ele, end = " ")
        print()
    # print("함수 작동 중")

def abc_print(a, b = '요', c = ".", *d):
    print(f"a : {a}")
    print(f"b : {b}")
    print(f"c : {c}")

def main():
    print_n_times("안녕하세요.", "파이썬", "반갑습니다.", n = 3)
    abc_print("안녕", "하세", "입니다.", "a", "b")

if __name__ == "__main__":
    main()
