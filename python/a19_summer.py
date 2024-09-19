import datetime
# datetime을 활용해서 month 데이터를 얻어와서 조건문으로 3~5는 봄 6~8은 여름 9~11 가을 12~2는 겨울
def main():
    month = datetime.datetime.now().month
    month = 4
    if month < 3:
        print(f"{month}월 겨울")
    elif month < 6:
        print(f"{month}월 봄")
    elif month < 9:
        print(f"{month}월 여름")
    else:
        print(f"{month}월 가을")
    # if 3 < month <= 5:
    #     print(f"{month}월 봄")


if __name__ == "__main__":
    main()
