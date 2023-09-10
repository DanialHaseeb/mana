"""
Competitive Programming 4

1.3.4.1.3

:author: Danial Haseeb
"""

from datetime import date

date_launch = date(2010, 8, 9)
date_today = date.today()

difference = (date_today - date_launch).days

print(date_launch.strftime("%A"))
print(f"{difference} day(s) ago")
