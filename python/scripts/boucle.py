#!/usr/bin/python
import math


def getPosition(t):

    x = 0.5 * math.cos(t/240)
    y = 0.5 * math.sin(t/120)
    return (x, y)
