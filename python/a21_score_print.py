
def main():
    score = float(input("학점 입력 -> "))
    try:
        if not score.isdigit:
            raise
        score - float(score)
        if score > 4.5:
            raise
        if score < 0:
            raise
    except:
        exit()

    if score == 4.5:
        print(f"{score}점 신")
    elif 4.2 <= score < 4.5:
        print(f"{score}점 교수님의 사랑")
    elif 3.5 <= score < 4.2:
        print(f"{score}점 현 체제의 수호자")
    elif 2.8 <= score < 3.5:
        print(f"{score}점 일반인")
    elif 2.3 <= score < 2.8:
        print(f"{score}점 일탈을 꿈구는 소시민")
    elif 1.75 <= score < 2.3:
        print(f"{score}점 오락문화의 선구자")
    elif 1.0 <= score < 1.75:
        print(f"{score}점 불가촉천민")
    elif 0.5 <= score < 1.0:
        print(f"{score}점 자벌레")
    elif 0.0 < score < 0.5:
        print(f"{score}점 플랑크톤")
    else:
        print(f"{score}점 시대를 앞서가는 혁명의 씨앗")


if __name__ == "__main__":
    main()
