import os
import sys

def main():
    print(os.path)
    print(__file__)
    print(os.getcwd())
    os.chdir("/home/test/Desktop/python/data")
    if os.path.exists("basic.txt"):
        print("파일이 이미 있습니다.")
        with open("basic.txt", 'a', encoding='utf-8') as file:
            file.write("this is file save data! add\n")
    else:
        with open('basic.txt', 'w', encoding = 'utf-8') as file:
            file.write("this is file save data! first\n")
            file.write("this is file save data! second\n")
            file.close()

if __name__ == "__main__":
    main()
