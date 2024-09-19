import math
# 사용자가 여러 숫자를 쉼표로 구분하여 입력을 받는다
# ex) 10, 20, 30, abc
# 합계 계산, 평균 계산, 최대값 계산, 최소값 계산
# 만약 문자가 있으면 무시하고 계산 진행, 무시된 값 출력
# 숫자가 없으면 유효한 숫자가 없습니다.
# format을 써서 자리수를 유효숫자 소수점 3번째 자리까지 출력
def main():
    user_input = input("쉼표를 이용해 여러 숫자 입력 -> ")
    
    split_values = user_input.split(",")
    
    index = 0
    tot = 0
    cnt = 0
    max = None
    min = None

    while index < len(split_values):
        current_number = split_values[index].strip()

        try:
            number = float(current_number)
            tot += number
            cnt += 1
            if max is None or number > max:
                max = number
            if min is None or number < min:
                min = number
        except ValueError:
            print(f"무시된 값: {current_number}")

    index += 1

    if cnt > 0:
        ave = tot/cnt
        print(f"합계: {tot:.3f}")
        print(f"평균: {ave:.3f}")
        print(f"최대값: {max:.3f}")
        print(f"최소값: {min:.3f}")
    else:
        print("유효한 숫자가 없습니다.")
1
if __name__ == "__main__":
    main()
