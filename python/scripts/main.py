import cercle
import boucle
from POC import *


def getPosition(t):

    t = t[0]

    t1 = cercle.getPosition(t)
    t2 = boucle.getPosition(t)

    v1 = Vector()
    v1.set(t1[0], t1[1])

    v2 = Vector()
    v2.set(t2[0], t2[1])

    return [v1, v2]
