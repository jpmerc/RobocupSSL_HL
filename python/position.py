#!/usr/bin/python
import math


def getPosition(t):

    # junk code to simulate real complex code
    j = 0
    for i in range(1000):
        j = math.cos(i**42)
        math.sin(j)

    # real code
    x = math.cos(t/1000)
    y = math.sin(t/1000)
    return (x, y)
