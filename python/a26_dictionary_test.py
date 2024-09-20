
def main():
    # 선언
    dict_a = {'a': 123}
    print(type(dict_a))
    print(dict_a)

    # 요소 추가
    dict_a['b'] = 456
    dict_a['a'] = '123'
    print(dict_a)

    # 요소 접근
    print(dict_a['a'], dict_a['b'])
    # print(dict_a['c'])          ket error
            
if __name__ == "__main__":
    main()
