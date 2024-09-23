class Test:
    def __new__(cls, *args, **kwargs):
        instance = super(Test, cls).__new__(cls)
        print(f" {args} 생성 되었습니다.")
        return instance

    def __init__(self, name):
        self.name = name
        print(f"{self.name} - 초기화 되었습니다.")

    def __del__(self):
        print(f"{self.name} - 파괴 되었습니다.")


def main():
    a = Test("a name")
    b = Test("b name")
    del a
    c = Test("c name")

if __name__ == "__main__":
    main()
