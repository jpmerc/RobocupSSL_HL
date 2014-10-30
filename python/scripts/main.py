import cercle
import boucle


def getPosition(t):

    t = t[0]
    period = 10000  # 10000ms, 10s

    if t % period < period / 2:
        return cercle.getPosition(t)
    else:
        return boucle.getPosition(t)
