import cv2

def main():
    img = cv2.imread("/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/build/lenna.bmp")
    cv2.imshow("image", img)
    cv2.waitKey(0)

if __name__ == "__main__":
    main()