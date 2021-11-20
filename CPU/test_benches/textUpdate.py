import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('tower.jpg', cv.IMREAD_GRAYSCALE)
img_data = []
rows, cols = img.shape

img_data.append(str(rows%256))
img_data.append(str(rows//256))

img_data.append(str(cols%256))
img_data.append(str(cols//256))

for row in range(rows):
	for col in range(cols):
		img_data.append(str(img[row][col]))

cv.imshow('image',img)
cv.waitKey(1000)

line_no = 0

while(True):
	f = open("updates.txt", "r")
	lines = f.readlines()
	while(line_no < len(lines)):
		coordinate, value = lines[line_no][:-1].split(' ')
		line_no += 1
		coordinate = int(coordinate) - 4
		value = int(value)
		img[coordinate//400][coordinate%400] = value
	cv.imshow('image',img)
	cv.waitKey(1)
cv.destroyAllWindows()
