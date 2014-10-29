#!/usr/bin/python
import math


def getPosition(t):

    x = 0.5 * math.cos(t/600)
    y = 0.5 * math.sin(t/600)
    return (x, y)
