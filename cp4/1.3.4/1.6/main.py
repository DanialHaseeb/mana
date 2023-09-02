def exists(L: list[int], v: int) -> bool:
	l = 0
	r = len(L) - 1

	for _ in range(20):
		if (l > r):
			return False

		mid = (l + r) // 2

		if (L[mid] == v):
			return True
		elif (L[mid] < v):
			l = mid + 1
		else:
			r = mid - 1

	return False

L = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(exists(L, 5))  # True
print(exists(L, 20))  # False
