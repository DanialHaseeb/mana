"""
Dreamer

:see: https://open.kattis.com/problems/dreamer

:author: Danial Haseeb
"""

import sys
import itertools


def is_leap(year: int):
	if year % 400 == 0:
		return True

	if year % 100 == 0:
		return False

	if year % 4 == 0:
		return True

	return False


class Date:
	def __init__(self, digits: tuple[str, ...]):
		tokens = "".join(list(itertools.chain.from_iterable(digits)))

		self.day = int(tokens[0] + tokens[1])
		self.month = int(tokens[2] + tokens[3])
		self.year = int(tokens[4] + tokens[5] + tokens[6] + tokens[7])

		self.days_in_months = { 1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30, 7: 31, 8: 31, 9: 30, 10: 31, 11:30, 12: 31 }

		if is_leap(self.year):
			self.days_in_months[2] = 29

	def is_valid(self):
		if self.year < 2000:
			return False

		if (self.month < 1) or (self.month > 12):
			return False

		if (self.day < 1) or (self.day > self.days_in_months[self.month]):
			return False

		return True

	def __hash__(self):
		return hash((self.day, self.month, self.year))

	def __eq__(self, other: object):
		if not isinstance(other, Date):
			return False

		return (self.day, self.month, self.year) == (other.day, other.month, other.year)

	def __lt__(self, other: object):
		if not isinstance(other, Date):
			return False

		if self.year == other.year:
			if self.month == other.month:
				return self.day < other.day

			return self.month < other.month

		return self.year < other.year

	def __repr__(self):
		return f"{self.day:=02} {self.month:=02} {self.year:=04}"


t = int(sys.stdin.readline().rstrip())

for i in range(t):
	digits = "".join(sys.stdin.readline().split())

	dates: set[Date] = set()

	earliest_date: Date | None = None

	for permutation in itertools.permutations(digits):
		date = Date(permutation)

		if date.is_valid():
			dates.add(date)

			if (date < earliest_date) or (earliest_date is None):
				earliest_date = date

	print(f"{len(dates)} {earliest_date if earliest_date is not None else ''}")
