"""
Competitive Programming 4

1.3.4.1.5

:author: Danial Haseeb
"""

birthdates = [(15, 5, 1990), (12, 4, 1985), (12, 5, 2000)]
birthdates.sort(key=lambda x: (x[1], x[0], -x[2]))
print(birthdates)
