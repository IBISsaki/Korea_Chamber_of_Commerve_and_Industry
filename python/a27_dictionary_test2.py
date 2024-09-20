
def main():
    dictionary = {
        "name": "7D 건조 망고",
        "type": "당절임",
        "ingredient": ["망고", "설탕", "메타중아황상나트륨", "치자황색소"],
        "origin": "필리핀",
    }
    # print(f'name: , {dictionary["name"]}')
    # print(f'type: , {dictionary["type"]}')
    # print(f'ingredient: , {dictionary["ingredient"]}')
    # print(f'origin: , {dictionary["origin"]}')
    for key in dictionary:
        print(f"{key} : {dictionary[key]}")
    for key, value in dictionary.items():
        print(f"{key} : {value}")

    dictionary["name"] = "8D 건조 망고"
    print(f'name: , {dictionary["name"]}')
    print(f"ingredient[1]: {dictionary['ingredient'][1]}")

    # 키 확인
    key = input("키 이력")
    if key in dictionary:
        print(f"value: {dictionary[key]}")
    else:
        print("그 키는 dictionary에 없습니다")

    value = dictionary.get(key)
    print(f"value : {value}")

    # 제거
    del dictionary["ingredient"]
    print("--" * 10)
    print(dictionary)
    re = dictionary.pop("name")
    print(dictionary, re)

    # valueerror
    dict_test = {1: "123"}
    print(dict_test)

if __name__ == "__main__":
    main()
