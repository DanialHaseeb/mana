"""
Square Deal

:see: https://open.kattis.com/problems/squaredeal

:author: Danial Haseeb

"""

import sys

class Rectangle:
	def __init__(self, width: int, height: int):
		self.width = width
		self.height = height

	def flipped(self):
		return Rectangle(self.height, self.width)

def parse():
	[h1, w1] = sys.stdin.readline().split()
	[h2, w2] = sys.stdin.readline().split()
	[h3, w3] = sys.stdin.readline().split()

	rectangle1 = Rectangle(int(h1), int(w1))
	rectangle2 = Rectangle(int(h2), int(w2))
	rectangle3 = Rectangle(int(h3), int(w3))

	return [rectangle1, rectangle2, rectangle3]

def can_form_square(r: list[Rectangle]):
	if r[0].height == r[1].height == r[2].height:
		if (r[0].width + r[1].width + r[2].width) == r[0].height:
			return True
		else:
			return False

	if (r[0].height == r[1].height) and (r[0].width + r[1].width == r[0].height + r[2].width ==  r[2].height):
		return True

	if (r[0].height == r[2].height) and (r[0].width + r[2].width == r[0].height + r[1].width == r[1].height):
		return True

	if (r[1].height == r[2].height) and (r[1].width + r[2].width == r[1].height + r[0].width == r[0].height):
		return True

	return False

r = parse()

if can_form_square(r):
	print("YES")
	sys.exit()

if can_form_square([r[0].flipped(), r[1], r[2]]):
	print("YES")
	sys.exit()

if can_form_square([r[0], r[1].flipped(), r[2]]):
	print("YES")
	sys.exit()

if can_form_square([r[0], r[1], r[2].flipped()]):
	print("YES")
	sys.exit()

if can_form_square([r[0].flipped(), r[1].flipped(), r[2]]):
	print("YES")
	sys.exit()

if can_form_square([r[0].flipped(), r[1], r[2].flipped()]):
	print("YES")
	sys.exit()

if can_form_square([r[0], r[1].flipped(), r[2].flipped()]):
	print("YES")
	sys.exit()

if can_form_square([r[0].flipped(), r[1].flipped(), r[2].flipped()]):
	print("YES")
	sys.exit()

print("NO")
