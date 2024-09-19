
def main():
    bo = bool()
    bo1 = True
    bo1 = 0.00000000001

    bo1 = [] # 아무 요소도 없으면 거짓
    bo1 = "" # ==
    
    if bo1:
        print("bo1 is True")
    else:
        print("bo1 is False")

    # c (!true) -> false
    # python (not True) -> False
    # c (Acondition && Bcondition)
    # python (Acondition and Bcondition)
    # c (Acondition || Bcondition)
    # python (Acondition or Bcondition)

if __name__ == "__main__":
    main()
