"""
Competitive Programming 4

1.3.4.1.8

:author: Danial Haseeb
"""

import itertools

elements = list(range(1, 21))

for r in range(len(elements) + 1):
  for subset in itertools.combinations(elements, r):
    print(subset)
