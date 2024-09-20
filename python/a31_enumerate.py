
def main():
    example_list = ['요소A', '요소B', '요소C']

    print(enumerate(example_list))
    for i, v in enumerate(example_list):
        print(f"{i} 번째는 {v}")

if __name__ == "__main__":
    main()