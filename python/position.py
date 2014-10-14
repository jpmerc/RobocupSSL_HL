#!/usr/bin/python
import math


def getPosition(t):
    x = math.cos(t/1000)
    y = math.sin(t/1000)
    return (x, y)
