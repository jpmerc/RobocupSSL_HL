#!/usr/bin/python
import math


def getPosition(t):

    # junk code to simulate real complex code
    j = 0
    for i in range(1000):
        j = math.cos(i**42)
        math.sin(j)

    # real code
    x = 0.5 * math.cos(t/500)
    y = 0.5 * math.sin(t/500)
    return (x, y)
