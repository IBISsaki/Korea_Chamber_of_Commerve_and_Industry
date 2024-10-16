import cv2
import numpy as np

folder = "/home/test/Desktop/AIOT_2024_ROBOT/OpenCV/cppTest/data/"
src = cv2.imread(folder + "frame.png")

Detector = cv2.QRCodeDetector()

info, points, _ = Detector.detectAndDecode(src)
    
if info:
    print(info) 
    print(points)
    points = np.int32(points).reshape(-1, 2)
    cv2.polylines(src, [points], True, (0, 0, 255), 2)

cv2.imshow("src", src)
    
cv2.waitKey()
